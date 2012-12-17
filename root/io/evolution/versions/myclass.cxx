int write_what(const char*what);
int readfile(const char *prefix = "veclong");

int compile(const char *version, const char *what = "myclass.h")
{
   static const TString incs( gSystem->GetIncludePath() );
   TString work( incs );
 
   work.Append( Form(" -DCASE_%s -DVERSION=%s ",version,version) ); 
   gSystem->SetIncludePath( work );
   TString lib; 
   if (strcmp(what,"myclass.h")==0) {
      lib.Form("lib%s",version);
   } else {
      lib.Form("lib%s%s",what,version);
      lib.ReplaceAll(".","_");
   }
   int r = !gSystem->CompileMacro(what,"k",lib);
   return r;
}

int wcomp(const char *version, const char *what = "myclass.h")
{
   int r = compile(version,what);
#ifdef ClingWorkAroundMissingDynamicScope
   if (!r) r = gROOT->ProcessLine(TString::Format("write_what(\"%s\");",version));
#else
   if (!r) r = write_what(version);
#endif
   return r;
}

int checkLibFirst(const char *what, int part)
{
   cout << "\nLoading library lib" << what << endl;
   int r = compile(what);
   if (r!=0) return r;

   gROOT->GetClass("MyClass")->GetStreamerInfo();
   gROOT->GetClass("MyClass")->GetStreamerInfos()->ls();
   
   if (part==0) {
      for (int i=1; i<3; ++i) {
         cout << endl << "Loading " << Form("myclass%d.root",i) << endl;
         TFile *f = new TFile(Form("myclass%d.root",i));
         gROOT->GetClass("MyClass")->GetStreamerInfos()->ls();
      }
   } else {
      for (int i=6; i<8; ++i) {
         cout << "Loading " << Form("myclass%d.root",i) << endl;
         TFile *f = new TFile(Form("myclass%d.root",i));
         gROOT->GetClass("MyClass")->GetStreamerInfos()->ls();
      }
   }
   return 0;
}

int checkFileFirst(const char *what, int part)
{
   if (part==0) {
      for (int i=1; i<3; ++i) {
         cout << "Loading " << Form("myclass%d.root",i) << endl;
         TFile *f = new TFile(Form("myclass%d.root",i));
         gROOT->GetClass("MyClass")->GetStreamerInfos()->ls();
      }
   } else {
      for (int i=6; i<8; ++i) {
         cout << "Loading " << Form("myclass%d.root",i) << endl;
         TFile *f = new TFile(Form("myclass%d.root",i));
         gROOT->GetClass("MyClass")->GetStreamerInfos()->ls();
      }
   }

   cout << "\nLoading library lib" << what << endl;
   int r = compile(what);
   if (r!=0) return r;

   gROOT->GetClass("MyClass")->GetStreamerInfo();

   gROOT->GetClass("MyClass")->GetStreamerInfos()->ls();
 
   return 0;
}


int runAddVersion(int mode, const char *whatlib) 
{
   return 1;
   switch(mode) {
   case 0:
      return wcomp(whatlib);
   case 1:
#ifndef ClingWorkAroundNoDotOptimization
      gROOT->ProcessLine(".O0");
#endif
      return checkLibFirst(whatlib,0);
   case 2:
      return checkFileFirst(whatlib,0);
   case 3:
      return checkLibFirst(whatlib,1);
   case 4:
      return checkFileFirst(whatlib,1);
   default:
      return 5; // Error case
   }
}

int runVecLong(int mode, const char *whatlib)
{
   switch(mode) {
      case 0:
         return wcomp(whatlib,"veclong64.h"); 
      case 1:
         compile(whatlib,"veclong64.h");
         return readfile();
      default:
         return 2; // Error case.
   }
}

