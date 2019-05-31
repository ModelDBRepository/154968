#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;
	
	
  int nelement;  // total number of elements(volume)
	int totalsteps;
	int istotalstepsknown;
	int neleflag;	
	//char* filename;
//	char* outfile;
    string filename;
    string outfile;
    string avgfile;
    string molnameinput;
    string multipleinput;
    string mollist;
    string cclohead;
    string cnumdata;
    string nrdpostfilename;
    string selmapname;

    string meshfilename;
    string subregion[50]; //max sub region number 50
    float subregavg[50][3][3]; //[subreg_name][0all_1:cyt_2:submem][//0avg//1variance//2std]   
    float subregavga0;
    float subregavga1;
    int subregavgacnt;
    float subregvolsuma;

    
    int subregcnt[50][3]; //[subreg_name_numbering][count for //0all//1dend//2cytosol] //need initialize
    float subregvolsum[50][3]; //[subreg_volumesum][count for //0all//1dend//2cytosol] //need initialize
    
    int subregioncount;
    int islistfound;
    int isallregavg;
    int isavgfilename;
    
    string regionheaderinfo[4000]; //max sub region number 50 //3000 element max
    float meshvolume[4000];
    
    string ccolheadtmp;
    
    
    
    size_t found;
  
  
	char argtmp[256];
	char mollisttmp[20];
  string cmollisttmp;
	
	int targetmolecule;
	int isprintscreen;
	int isforinformation;
	int isextractingall;
	int isextractingmultiple;
	int nmultiple;
	
	int totalmoleculekind;
	int isSpcfound;
	
	  int nmolcount;
	    int is0sthead;
	    int dotcount;
	    int dataalinecount;
	    
	    float divnptonM;
	    
	    float f_dt;


	    
	    //for x sort
      int sortlinecount;
      int sortcharcount;
      int sortsublinecount;
      int sortblockcount;
      char sorttmp[20];

      
      int isdatanumberofmolecule;
     
	    int isxsort;
	    int isysort;
	    int isaverage;
	    float xyout_cord[2000];
 	    float xyout_datasum[2000];
 	    float xyout_numberadd[2000];
 	    float xyout_volumesum[2000];
 	    
 	    float xyout_varsum[2000];
      float tmpvar;

	    int nselected;
      int ncoord;
	    int xyout_cmap[2000];
 	    int xyout_nelement[2000];
 	    float xyout_x[2000];
 	    float xyout_y[2000];
 	    float xyout_volume[2000];
 	    
 	    





//int nrdhead[205][7][20]; //[ncolforspec][subtcount][char]
//double nrddata[205][16]; //[ncolforspec][timestep]
 //	int nrdhead[2000][7][20]; //[ncolforspec][subtcount][char]
 	//double nrddata[23][8000]; //[ncolforspec][timestep]//no need?
	char tmpchar[20]; 	
	
	
	
	void CodeTest();
	void ReadData();
  void ReadMesh();
	void Readsubdomain();
	void Initialize();
  void Chknumber();
 	
 	

using namespace std;