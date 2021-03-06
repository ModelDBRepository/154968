#include "nrdpost.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main(int argc, char* argv[])
{
  
  Initialize();
  cout << "Initialize...\n";

  int i,j,k,ofcount,ifcount; 

 char last_option = '\0';

  ofcount = 0;
  ifcount = 0;
  

// cout << "1Parsing\n";
  for (i = 1; i < argc; ++i)
  {

// cout << "2Parsing\n";
     
     if (argv[i][0] == '-') // looks like an argument option to me (first char is '-')
     {
        switch(argv[i][1]) // explore 2nd char
        {
            //no use
            //case 'n': /* do the c option stuff, set a flag or something */ 
            //for (j=3; j<50 ; j++)
            //{
            // if( argv[i][j] == ']')break;
            //  argtmp[j-3] = argv[i][j];
            //}
            //nelement = atoi(argtmp);
            //for (k = 1; k < 50; ++k) { argtmp[k] = ' '; }
            //cout << nelement <<"!" <<'\n';
            //break;
            
            case 'v': /* do the c option stuff, set a flag or something */ 
            isprintscreen = 1;
            cout << isprintscreen <<"!" <<'\n';
            break;
            
            case 'h': /* do the c option stuff, set a flag or something */ 
            isforinformation = 1;
            isextractingall = 0;  
            cout << "Gathering datafile information!" <<'\n';
            break;
            
            case 'g': /* do the c option stuff, set a flag or something */ 
            isforinformation = 1;
            isextractingall = 0;  
            cout << "Gathering datafile information!" <<'\n';
            break;

 
            case 'x': /* do the c option stuff, set a flag or something */ 
            isxsort = 1;
            cout << "For x-sort!" <<'\n';
            break;

            case 'y': /* do the c option stuff, set a flag or something */ 
            isysort = 1;
            cout << "For y-sort!" <<'\n';
            break;

            case 'a': /* do the c option stuff, set a flag or something */ 
            isaverage = 1;
            isxsort = 1;
            //isxsort = 1;
            cout << "For sub domain average!" <<'\n';
            break;
            

 
            case 'n': /* do the c option stuff, set a flag or something */ 
             isdatanumberofmolecule = 1;
            cout << "data type is [number of molecules]" <<'\n';
            break;
 

            case 't': /* same thing with the o option */ 
            for (j=3; j<256 ; j++)
            {
              if( argv[i][j] == ']')break;
              argtmp[j-3] = argv[i][j];
            }
            totalsteps  = atoi(argtmp);
            istotalstepsknown = 1;
            for (k = 1; k < 256; ++k) { argtmp[k] = ' '; }
            cout<< "Total output steps" <<totalsteps <<'\n';
            break;
            
             
            case 'm': /* same thing with the o option */ 
            for (j=3; j<256 ; j++)
            {
              if( argv[i][j] == ']')break;
              molnameinput.push_back(argv[i][j]);
            }
              isextractingall = 0;
              found=molnameinput.find(",");
              if (found==string::npos)
              {
              outfile.append("-");
              outfile.append(molnameinput);
              outfile.append(".txt");
              cout<<"#Target molecule name: "<< molnameinput <<'\n';
              }
              if (found!=string::npos)
              { isextractingmultiple = 1;
               cout <<"multiple output" << "\n";
                 multipleinput = molnameinput;
                    for (int i=1; i<300; i++)
                    {
                      found=multipleinput.find(",");
                      multipleinput.erase(0,found+1);
                      if (found==string::npos) break;
                      nmultiple = nmultiple+1;
                      cout <<"Total Multiple outputs: "<< nmultiple << "\n";
                    }
                 multipleinput.clear();
                 multipleinput = molnameinput;
                 molnameinput.clear();
              }

            break;
            
           
            case 'i': /* input file name */ 
            for (j=3; j<256 ; j++)
            {
              if( argv[i][j] == ']')break;
              filename.push_back(argv[i][j]);
            }
              outfile = filename;
              outfile.erase(filename.length()-4,filename.length());
              //cout<< outfile <<'\n';
            break;
            
            case 'r': /* all subregion filename*/ 
            for (j=3; j<256 ; j++)
            {
              if( argv[i][j] == ']')break;
              meshfilename.push_back(argv[i][j]);
            }
            isallregavg = 1;
            cout<<"Input Meshfile Name :" << meshfilename <<'\n';
            ReadMesh();
            break;

            case 'o': /* same thing with the o option */ 
            outfile.clear();
            avgfile.clear();
            isavgfilename = 1;
            for (j=3; j<256 ; j++)
            {
              if( argv[i][j] == ']')break;
              outfile.push_back(argv[i][j]);
              avgfile.push_back(argv[i][j]);
            }
            break;

            default: /* oops, unknown command!!!! */
           	cout << "oops, unknown command!!!!";
        }
        last_option = argv[i][1];
     } 
     else
     {
         // this is not a -option argument, so it must be a textual argument
         //do something with it (*)
        switch(last_option) // explore last command
        {
            case 'n': /* assign argv[i] to the filename buffer */ break;
            cout << "oops, unknown command!!!!";
            default: 
            cout << "oops, unknown command!!!!";
               // oops, unknown option or last option did not expect a text 
               // text special argument for that option!!!!
        }
        last_option = '\0'; // the last argument (this last argument) is text and
                                     // not an option argument!
      }
    }

     //              nrdpostfilename.append("_");  nrdpostfilename.append(molnameinput);  nrdpostfilename.append(".txt");
     
           cout<<"Input file name : "<<filename <<'\n';
//           cout<<"Target molecule number :"<<targetmolecule <<'\n';
           if (isxsort == 1 &&  isaverage == 0)
           {
                    outfile= "NRDpost_DUMP.txt";
             cout<<"Output file name : NRDPost_Xdataout"<<"-"<<molnameinput<<".txt" <<'\n';
              if (isdatanumberofmolecule == 0) cout<<"Data type : Concentration" <<'\n';
              if (isdatanumberofmolecule == 1) cout<<"Data type : Number of molecules" <<'\n';
              
           }
           if (isysort == 1)
           {
                   outfile= "NRDpost_DUMP.txt";
             cout<<"Output file name : NRDPost_Ydataout"<<"-"<<molnameinput<<".txt" <<'\n';
              if (isdatanumberofmolecule == 0) cout<<"Data type : Concentration" <<'\n';
              if (isdatanumberofmolecule == 1) cout<<"Data type : Number of molecules" <<'\n';
           }
           
           if (isxsort == 0 && isysort == 0 && isallregavg ==0)
           {
                        if (isforinformation != 1) cout<<"Output file name :" <<outfile <<'\n';
           }

           if (isxsort == 1 && isaverage == 1)
           { outfile= "NRDpost_DUMP.txt";
             cout<<"Output file name : NRDPost_Adataout"<<"-"<<molnameinput<<".txt" <<'\n';
             if (isdatanumberofmolecule == 0) cout<<"Data type : Concentration" <<'\n';
             if (isdatanumberofmolecule == 1) cout<<"Data type : Number of molecules" <<'\n';
           }
           
           if (isallregavg == 1)
           {
             outfile= "NRDpost_DUMP.txt";
             cout<<"Output file name : NRDPost_AllRegion_dataout"<<"-"<<molnameinput<<".txt" <<'\n';
             if (isdatanumberofmolecule == 0) cout<<"Data type : Concentration" <<'\n';
             if (isdatanumberofmolecule == 1) cout<<"Data type : Number of molecules" <<'\n';
           }


	//CodeTest();
	//cout << "CodeTest();\n\n\n";

  if (isforinformation == 1)
  {
     Chknumber();
     
     cout << "\n";
     cout << "###Example Parameters###\n";
     cout << "\n";
     cout << "#Gathering datafile information: $>./NRDpost -i[DATA FILE NAME] -h\n";
     cout << "\n";
     cout << "#Extract single molecule: $>./NRDpost -i[DATA FILE NAME] -m[MOLECULE NAME]\n";
     cout << "#Extract all molecules: $>./NRDpost -i[DATA FILE NAME]\n";     
     cout << "Example: $>./NRDpost.exe -i[Multisp.out-conc.txt] -m[IP3]\n";
     cout << "Example: $>./NRDpost.exe -i[Multisp.out-conc.txt] -m[IP3,PKA,Ca]\n";
     cout << "Example: $>./NRDpost.exe -i[Multisp.out-conc.txt]\n";
     
     cout << "\n";
     cout << "#Spatial AVG (need VNRD_selmap.txt): $>./NRDpost -i[FILE NAME] -m[M] -x(or -y)\n";
     cout << "Example: $>./NRDpost -i[Multisp.out-conc.txt] -m[cAMP] -x\n";
     cout << "Example: $>./NRDpost -i[Multisp.out-conc.txt] -m[cAMP] -y\n";
     cout << "\n";
     cout << "#Sub-region AVG,VAR,STD (need VNRD_avg_selmap.txt):\n";
     cout << "$>./NRDpost -i[FILE NAME] -m[M] -a\n";
     cout << "Example: $>./NRDpost -i[Multisp.out-conc.txt] -m[IP3] -a\n";
     cout << "\n";
     cout << "#All-Subregion AGV,VAR,STD (need mesh file):\n";
     cout << "$>./NRDpost -i[FILE NAME] -m[M] -r[MESHFILE]\n";
     cout << "Example: $>./NRDpost -i[Multisp.out-conc.txt] -m[IP3] -r[ModelA_mesh.txt]\n";
     cout << "\n";
     cout << "IMPORTANT! add -n switch at the end of line for a original data type 'number of molecules'\n";
     cout << "for averaging data. Default setting for averaging is 'concentration'\n";
     cout << "Output data is always written in concentration [nM] for averaging.\n";
     cout << "Abbrebation: AVG(average),STD(standard deviation),SM(submembrane),CT(cytosol)\n";
     cout << "\n";
     cout << "#Additional options\n";
     cout << "-t[TIMESTEPS]: User defined total timesteps\n";
     cout << "-t[#ELEMENT]: User defined total element number \n";
     cout << "-o[OUTFILE NAME]: User defined outfile name (don't put file extension)\n";
     cout << "-v: Print screen sorting process\n";
     cout << "\n";
     cout << "Send email to bkim14@gmu.edu for any problems using NRDPost.\n";
     cout << "Last updated on 06/14/2011.\n";
    
  }
  
  
  
    if (isxsort == 1 || isysort == 1 || isallregavg ==1 || isaverage == 1 )
		{
		  if (isextractingall == 1 || isextractingmultiple == 1)
		  {
  		  cout<<"!!!! Currently multiple molecule process only works for [extracting].  \n";
	  	  cout<<"!!!! Use batch process for multiple molecules [averaging] - Exiting....  \n";
      	return 0;
			}
		}
		
		
  
  
  if (isforinformation == 0 && isextractingall ==0)
  {
		
		
    Chknumber();
    
     if (isxsort == 1) //xsort
     {
       Readsubdomain();
       ReadData();
     }
     if (isysort == 1) //ysort
     {
       Readsubdomain();
       ReadData();
     }
     if (isxsort == 0 && isysort == 0) //normal extracting
     {
         if (isextractingmultiple == 0){ ReadData();}
         if (isextractingmultiple == 1)
         {
           for (int i=0; i<nmultiple; i++)
           {
             molnameinput.clear();
             molnameinput = multipleinput;

//             cout << molnameinput << "\n";
//             cout << multipleinput << "\n";
             
             found = molnameinput.find(",");

              cout << "Extracting molecules remain:"<<molnameinput << "\n";
  //            cout << "is it here?"<<multipleinput << "\n";

             if (i < nmultiple-1)multipleinput.erase(0,found+1);
//             cout << "is it here?"<<found << "\n";
             if (i < nmultiple-1)molnameinput.erase(found,molnameinput.length());
            
             outfile.append("-");
             outfile.append(molnameinput);
             outfile.append(".txt");
             cout<<"#Target molecule name: "<< molnameinput <<'\n';
             Chknumber();
             ReadData();
             outfile.erase(outfile.length()-(5+molnameinput.length()),outfile.length());
             molnameinput = multipleinput;
           }
         }
     }
     
  }

  if (isforinformation == 0 && isextractingall ==1)
  {
        
        cout << "Extractign all molecules!" << "\n";    
        Chknumber();
        int tmtmp;
        tmtmp = totalmoleculekind;
        for (int i=0; i<tmtmp; i++  )
        {
              targetmolecule = i;
              if (i > 0)
              {
                 outfile.erase(outfile.length()-(5+molnameinput.length()),outfile.length());
              } 
              Chknumber();
              outfile.append("-");
              outfile.append(molnameinput);
              outfile.append(".txt");
                            
              cout<< "!Extrating file name" <<filename <<'\n';
              ReadData();
        }
  }


	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ReadMesh()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReadMesh()
{
  cout << "Start reading Mesh file" << "\n";

//meshfilename
//meshvolume[4000]

  char ch;
  int elementcount;
  int meshcolumncount;
  meshcolumncount = 0;
  elementcount = -1;
  string tmpmeshvol;
  ifstream fmeshin(meshfilename.c_str());
  tmpmeshvol.clear();
      while(fmeshin.get(ch))
    	{
        tmpmeshvol.push_back(ch);
        if (ch == ' ') 
        {
          meshcolumncount = meshcolumncount+1;
          if (elementcount >=0 && meshcolumncount == 15)
          {
            //cout << elementcount << " "<< meshcolumncount << " "<< tmpmeshvol;
            meshvolume[elementcount] = (float)atof(tmpmeshvol.c_str());
           // cout << elementcount << " "<< meshvolume[elementcount];
          }
          tmpmeshvol.clear();
        }
   	  
        if (ch == '\n') 
        {
         tmpmeshvol.clear();
         elementcount = elementcount+1;
         meshcolumncount = 0;
        // cout << "\n";
        }
    	  
    	}//while(fselmapin.get(ch))
    	
      fmeshin.close();
    	

  cout << "Reading Mesh file done!" << "\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ReadMesh() -end////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Readsubdomain()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Readsubdomain()
{
  
  cout << "start reading subdomain" << "\n";
  char ch;
  sortlinecount = 0;
  sortcharcount = 0;
  sortsublinecount = 0;
  sortblockcount = 0;
  
  selmapname = "VNRD_selmap.txt";
  if (isxsort == 1 && isaverage == 1)
  {
    selmapname.clear();
    selmapname = "VNRD_avg_selmap.txt";
  }
  ifstream fselmapin(selmapname.c_str());

      while(fselmapin.get(ch))
    	{

          sorttmp[sortcharcount] = ch;
     	    sortcharcount = sortcharcount+1;

    	      	  if (ch == '\n') 
              	 {
              	  
              	  if (sortcharcount == 2) // if it is empty line
              	  {
                	   if (isprintscreen == 1) cout << "\n";
                	  sortsublinecount = 0;
              	  } 
              	  else
              	  {
              	    // assign all data here based on the block count, subline count.
              	    if (sortblockcount == 0 && sortsublinecount ==0) {nselected = atoi(sorttmp); }
              	    
                         if (sortsublinecount == 1)
                          {
                              xyout_cmap[sortblockcount] = atoi(sorttmp);
                              if (ncoord <= xyout_cmap[sortblockcount]) ncoord = xyout_cmap[sortblockcount] + 1;
                            //  cout << "test:" <<ncoord << "\n";
                          }
                    if (sortsublinecount == 2) xyout_nelement[sortblockcount] = atoi(sorttmp);
                    if (sortsublinecount == 3) xyout_x[sortblockcount] = (float)atof(sorttmp);
                    if (sortsublinecount == 4) xyout_y[sortblockcount] = (float)atof(sorttmp);
                    if (sortsublinecount == 5) xyout_volume[sortblockcount] = (float)atof(sorttmp);
              	    
                	  if (isprintscreen == 1) cout << sortblockcount << ": " << sortsublinecount <<" : " << atof(sorttmp) << "\n";  
                	  if (sortsublinecount == 5) sortblockcount =  sortblockcount + 1;
              	  }
              	  
              	  sortlinecount = sortlinecount+1;
             	    sortsublinecount = sortsublinecount +1;
             	    sortcharcount = 0;
             	    //cout << atof(sorttmp) << "\n";
             	 
             	    
             	     for (int i=1; i<20; i++)
             	      {
             	        sorttmp[i] = ' ';
             	      }
              	 }
    	}

  fselmapin.close();
  
  cout << "Number of selected elements : " << nselected << "\n";
  cout << "Number of sorted coordinate : " << ncoord << "\n";
  //for (int i = 0; i < nselected ; i++)
  //{
    //cout <<  xyout_volume[i] << "\n";
  //}
  
  
  
  
  
  cout << "end reading subdomain" << "\n";
}
  
  
  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Chknumber()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
void Chknumber()
{
  
    if (isforinformation == 1) cout << "Target # list  - start" << "\n";
    
  char ch;
  int nelecount;
  int stepcounts;
  stepcounts = 0;
  dotcount = 0;
  is0sthead = 0;
  nmolcount =0;
  nelement = 0;
  neleflag = 0;
  nelecount =0;
  dataalinecount = 0;
//  ifstream fnum("NURDdata.txt");
  ifstream fnum(filename.c_str());
  

      while(fnum.get(ch))
    	{
            //if (istotalstepsknown == 1 && stepcounts == 1) break;
            if (ch == '\n') 
        	  {
        	     stepcounts =  stepcounts +1;
        	     dotcount = dotcount+1;
        	     if (stepcounts == 1) 
        	     {
        	          if (isforinformation == 1) cout <<  "\n" <<"Target # list  - end" << "\n\n";
        	          cout << "# of total elements - " <<  nelement <<"\n\n";
        	         if (isforinformation == 1) break;
        	         if (istotalstepsknown == 0)cout << "Scanning number of total outputsteps..." << "\n";
        	         
        	         if (istotalstepsknown == 1) break; // do linescan only once for multiple molecules
         	     }
               	  if (dotcount >= 300)
              	  {
                    cout << stepcounts << " lines scanned" << "\n";
                    dotcount =0;
                  }
            
        	  }
            // line counting//////////////////////////////////////////////////////////
            
        
        // header parsing//////////////////////////////////////////////////////////            
        if (stepcounts == 0) // check column headers only when totalsteps=0. it is column header.
        {
            if (ch == ' ' && neleflag == 1) nelement = nelement+1; // eleflag -> 'th element number 
            if (nelecount == 2 && ch =='_') //
                 {
                    nelecount = 0; //at first header column of element for extracting molecule name, pasing work happens only nelecount == 0
                    neleflag = neleflag + 1; //th number of molecules and passing all the 
                    is0sthead = 1; // noe nelecount is 0, so 0th element. -> is0shead is set to 1
                    isSpcfound = 0;
                 }
                 
            //this is for finding 1st column header and set nelecount 2 when we find "0" in the "Vol_0_d"
            //change this to find "Vol_0_"
            if (nelecount == 2 && ch !='_') nelecount = 0; //ch !='_' for checking space between headers
            if (nelecount == 1 && ch =='0') nelecount = 2;  //ch=='0' is checking vol number "0" int the data
            if (nelecount == 1 && ch !='0') nelecount = 0;
            if (nelecount == 0 && ch =='_') nelecount = 1;

//time Vol_0_dendrite1_submembrane_Spc_Ca Vol_1_dendrite1_cytosol_pointB1_Spc_Ca Vol_2_
//Vol_359_PSD_cytosol_sa3[5].pointA_Spc_PKAc_PDE4D_cAMP

//            if (is0sthead == 1 && isforinformation == 1) 
            if (is0sthead == 1) //parsing only happens here when  it is 1st column header in corresponding molecules
            {
              mollisttmp[nmolcount] = ch; //needs to change here with string 
              if (ch != ' ')cmollisttmp.push_back(ch);
              
              nmolcount = nmolcount +1;
              if (ch == '_')
              {
                nmolcount = 0; // is this emptying stroage when we meet '_' we need to add Spc parsing here
                //cout << "string has: " << cmollisttmp<< "--"<< cmollisttmp.compare("Spc_") << "\n";
                if (cmollisttmp.compare("Spc_") == 0)
                {
                   isSpcfound = 1;
                   cmollisttmp.clear();
                }
                if (isSpcfound != 1)cmollisttmp.clear();
               // cout << "string has: " << cmollisttmp << "##\n";
              }

              
              if (ch == ' ') //when it reaches to the end
                {
                  cout << neleflag-1 << "-"; // n th molecule numbering
                                     for (int i=0; i<nmolcount-1 ;i++)
                                     {
                                       mollist.push_back(mollisttmp[i]);
                                     }
                                      //cout << mollist << "!"; //molecule name
                                      cout << cmollisttmp; //molecule name
                                      
                                      
                                      totalmoleculekind = neleflag;
                                            //if (molnameinput.compare(mollist)==0 && isextractingall == 0)
                                            if (molnameinput.compare(cmollisttmp)==0 && isextractingall == 0)
                                            {
                                              targetmolecule = neleflag-1;
                                              cout <<"[Extracting!]"<< "\n" ;
                                            }
                                            
                                            if (targetmolecule == (neleflag-1) && isextractingall == 1)
                                            {
                                              //molnameinput = mollist;
                                              molnameinput = cmollisttmp;
                                            }
                                     
                                      for (int i=0; i<20-nmolcount ;i++)
                                     {
                                       cout << " ";
                                     }
                   dataalinecount = dataalinecount+1;
                   is0sthead =0;
                   nmolcount =0;
                   mollist.clear();
                   
                   if (dataalinecount >= 3) 
                   {
                      cout << "\n";
                      dataalinecount = 0;
                   }
                } //if (ch == ' ') 
            }
        }//if (totalsteps == 0)
         // header parsing//////////////////////////////////////////////////////////

    	} //getch() end
 
 if (istotalstepsknown == 0)totalsteps = stepcounts - 1;
 istotalstepsknown = 1; // after get line numbers
  
  if (isforinformation == 0) cout << "\n";
  fnum.close();

  if (isforinformation == 0) cout << "# of totalsteps - " << totalsteps <<"\n";

  cout << "# of molecule kind - " << totalmoleculekind <<"\n";
  
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Initialize()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Initialize()
{
  
  isallregavg = 0;
  totalmoleculekind =0;
  isprintscreen = 0;
  isforinformation = 0;
  isextractingall = 1;
  isextractingmultiple = 0;
  nmultiple = 1;
  isavgfilename = 0;

  divnptonM = 0.6022141527;
  
  f_dt = 1.0;
  
 isxsort = 0;
 isysort = 0;
 isaverage = 0;
 nselected =0; 
 ncoord = 0;
 
 subregioncount = 0;
 
 	totalsteps = 0;
	istotalstepsknown = 0;
 
 isdatanumberofmolecule = 0;
 
     for (int i=0; i< 2000; i++)
      {
       xyout_cord[i]=0.0f;
       xyout_datasum[i]=0.0f;
       xyout_volumesum[i]=0.0f;
       xyout_numberadd[i]=0.0f;
       xyout_cmap[i]=0;
      	xyout_nelement[i]=0;
      	xyout_x[i]=0.0f;
      	xyout_y[i]=0.0f;
      	xyout_volume[i]=0.0f;

        xyout_varsum[i]=0.0f;
     	}    
 	    
     for (int j=0; j< 20; j++)
      {
        	mollisttmp[j] = ' ';
        	molnameinput[j]=' ';
      }

}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ReadData()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ReadData()
{
  

  	cout << "Start ReadData\n";

	int count;     //count each char of words
	int spicescount;//molecule count
	int ncolforspc; //// when this reaches to nelement, spicescount+1 == 1~205
	int coltitlecount;// start from -1 since 1st column is timestep, count columns from 0 to total in NRD data files
	int subtcount; //subtitie count.. eg vo1 = 0 num = 1 dent = 2 
  	  
	int subct;
	int charsave;
	int breakloop;
	int i;
	int j;
	int k;
	char ch;

	
	subtcount = 0;
	spicescount = 0; // 0th spices are 1st spices.
	coltitlecount =-1; //start from -1 since 1st column is timestep
	ncolforspc = -1; // when this reaches to nelement, spicescount+1

	charsave = 1; //0 is off
	breakloop = 0;
  
  
  if (totalsteps < 1) 
  {
    cout << "no input parameters" << "\n";
    return;
  }
  
	for ( i = 0; i<20 ; i++)
	{
		tmpchar[i] = '_'; // clean memory garbage 
	}
	



	//postfile = "postfile.txt";
    	ifstream fin(filename.c_str());
  	fin.precision(15);
  	cout.precision(15);
           
          
   	ofstream fout(outfile.c_str());
   	//ofstream fout(outftmp);
	fout.precision(15);
	
    	count = 0;
	i = 0;
	/////////////////////////////////////////////column HEAD parsing  /////////////////////////////////

fout << "time" << " ";

     	while(fin.get(ch))
    	{


      		if (ch == ' ')
      		{
      		   charsave = 0;
      		} 
	      	if (ch == '_') 
	      	{
	      	   charsave = 0; 
     				 cclohead.push_back(ch); //string way!
	      	} 
	       	if (ch == '\n') { charsave = 0; breakloop = 1;} //also need to break  lets add

	      	if (charsave == 1)
	      	{
  		    	if (ch != '_' && ch != ' ' && ch != '\n' )
      			{
      				//tmpchar[count] = ch;
      				count = count+1;
      				cclohead.push_back(ch); //string way!
      		 	}
	       	}

	      	if (charsave == 0)
	      	{
        			//for ( i = count; i<20 ; i++)  { tmpchar[i] = '_'; } // fill up garbage space
            			if (spicescount == targetmolecule && ncolforspc != -1)
            			{ 
            	      if (isprintscreen == 1) cout << spicescount << " == " << coltitlecount <<"/"<< ncolforspc << "- " << subtcount << "-----  " << tmpchar << "\n";
            	      
            	      // sorting module needs to be added!!!!!!!!!!!!!!!!!!!! based on the number of elements == ncolforspc, tmpchar is data
            	      
            			if (subtcount == 2)
            			{
            				// remoevd for string wayfor ( i = 0; i<20 ; i++){nrdhead[ncolforspc][subtcount][i] = (int)tmpchar[i];}
            				// 	int nrdhead[2000][7][20]; //[ncolforspec][subtcount][char]
            				//cout << ncolforspc <<"-"<<nrdhead[ncolforspc][0]<< " ";
            			} //only save vol number
            			}
        			//if (spicescount == targetmolecule && ncolforspc != -1) fout << spicescount << " == " << coltitlecount <<"/"<< ncolforspc << "- " << subtcount << "-----  " << tmpchar << "\n";
        		  	charsave = 1;
        		   	count = 0;
        		  	subtcount +=1;
        		   	if (breakloop == 1) break;
	    	  }//if (charsave == 0) end
		
	    	if (ncolforspc == nelement) {ncolforspc = 0; spicescount += 1;} //need nelement later

             
    		if (ch == ' ' && ncolforspc > -1)  // for 0th molecules, ncolspec -1 means time column since it counts space
    		{ 


    		              
    			if (spicescount == targetmolecule) fout <<cclohead << " ";  //string way!

          if (spicescount == targetmolecule)
          {
//    			subregion[0] = cclohead;
//    			subregion[0].erase(0,4);
          cclohead.erase(0,4);
          cclohead.begin();
          cclohead.erase(0,cclohead.find("_")+1);
          cclohead.begin();
          
          size_t founddot;
          founddot = cclohead.find(".");
//          if (founddot != string::npos)
//          {
//              ccolheadtmp.assign(cclohead,0,cclohead.find("."));       //remove pointA     no need to, reserve for future use
//          }
//          else
//          {
               ccolheadtmp.assign(cclohead,0,cclohead.find("_Spc"));   //need to remove pointB1 at cytodol_pointB1
//          }

//          cout << ncolforspc << " " <<ccolheadtmp << "\n";

         
          regionheaderinfo[ncolforspc] = ccolheadtmp; //store column header information to nelement array
          
          //subregioncount // start from 0
          //string subregion[50]; max 50 subregion set.
          //cytosol , submembrane

          string tmpreginfo;
          tmpreginfo.assign(ccolheadtmp,0,ccolheadtmp.find("_")); //get first subregion info


                  // cout << subregioncount << "\n";
          if (subregioncount == 0)// find name and add to the subregion list
          {
           subregion[0] = tmpreginfo;
  //         cout << subregion[0] << "\n";
           subregioncount = subregioncount+1;
          }
          else
          {
              islistfound = 0;
              for (int i=0 ; i<subregioncount; i++)
              {
                 if (subregion[i].find(tmpreginfo) != string::npos) // find name and add to the subregion list when it not found
                 {
                    islistfound = 1;
                 }
              }
              
              if (islistfound == 0)
              {
                   subregion[subregioncount] = tmpreginfo;
                   //cout << subregion[subregioncount] << "\n";
                   subregioncount = subregioncount+1;
              }
          }//          if (subregioncount == 0)// find name and add to the subregion list
              


          tmpreginfo.clear();
          
//    string subregion[50]; //max sub region number 50
//    float subregavg[50][3][3]; //[subreg_name][0all_1:cyt_2:submem][//0avg//1variance//2std]   
//    int subregioncount; //need volume information for average!
          
     			}    //      if (spicescount == targetmolecule)
     			
     			cclohead.clear(); //string way!     			

    		} 
   		if (ch == ' ')  // for 0th molecules, ncolspec -1 means time column since it counts space
   		{
   		       			cclohead.clear(); //string way!     			
    			coltitlecount+=1; ncolforspc+=1; subtcount = 0;
   		}
       	    		
     }//while(fin.get(ch))end
	/////////////////////////////////////////////column HEAD parsing end /////////////////////////////////
	cout << "write header start" << "\n";
	
//	fout << "time" << " ";
	for (i = 0; i < nelement; i++) 
	{
		for (subct = 0; subct < 6; subct ++)
		{		
			for ( j = 0; j<15 ; j++)
			{
//				fout << (char)nrdhead[i][subct][j]; //writing column header
				//if ((char)nrdhead[i][subct][j] == '_') break; //this add '_' at the end
			}
		}
		fout << " ";
		//fout << "header" << i << " ";
	} //for (i = 0; i < nelement; i++) end
		fout << "\n";
	cout << "write header - done" << "\n";

  if (isallregavg == 1) 
  {
      cout << "Subregion list :"<<"\n";                         
      for (int i=0;i<subregioncount;i++)
      {
              cout << i << " "  << subregion[i] << "\n";                         
      }
  }
   

	/////////////////////////////////////////////column Number Data reading/////////////////////////////////
	cout << "Processing number data ..." << "\n";

          
 	if (isaverage == 1 || isxsort==1 || isysort==1)
 	{
 	 
 	if (isaverage == 0 && isxsort==1 ) {   	  nrdpostfilename.clear();	nrdpostfilename = "NRDPost_Xdataout"; nrdpostfilename.append("-");  nrdpostfilename.append(molnameinput);  nrdpostfilename.append(".txt");}
 	if (isaverage == 0 && isysort==1 ) {   	  nrdpostfilename.clear();	nrdpostfilename = "NRDPost_Ydataout"; nrdpostfilename.append("-");  nrdpostfilename.append(molnameinput);  nrdpostfilename.append(".txt");}
 	if (isaverage == 1 && isxsort==1 ) {   	  nrdpostfilename.clear();	nrdpostfilename = "NRDPost_Adataout"; nrdpostfilename.append("-");  nrdpostfilename.append(molnameinput);  nrdpostfilename.append(".txt");}

//              nrdpostfilename.append("_");  nrdpostfilename.append(molnameinput);  nrdpostfilename.append(".txt");


   	if (isavgfilename == 1)
   	{
   	  avgfile.append(".txt");
   	  nrdpostfilename.clear();
   	  nrdpostfilename = avgfile;
   	}
 	
 	}
 	else nrdpostfilename = "NRDPost_DUMP1.txt";

 	if (isallregavg == 1)
 	 {
 	    nrdpostfilename.clear();	nrdpostfilename = "NRDPost_AllRegion_dataout"; 
 	    nrdpostfilename.append("-");  nrdpostfilename.append(molnameinput);  nrdpostfilename.append(".txt");
     	if (isavgfilename == 1)
     	{
     	  avgfile.append(".txt");
     	  nrdpostfilename.clear();
     	  nrdpostfilename = avgfile;
     	}
 	 }


 	
  ofstream sout(nrdpostfilename.c_str());
  
	   	cnumdata.clear();
        for (j = 0; j < totalsteps ; j++)
        { 
	      	ncolforspc = -1; // 
	       	spicescount = 0;
    	  	coltitlecount = -1;
    	  	breakloop = 0;
    	  	
    	  	 if (j != 1) fout << f_dt*(float)j << " "; // here to put timesteps instead of number of lines //exclude j=1 since this writes first
    	  	
    	  	
    	  	//initialize avg,,var,std memory
    	  	//float subregavg[50][3][3]; //[subreg_name][0all_1:cyt_2:submem][//0avg//1variance//2std]   
          //int subregcnt[50][3]; //[subreg_name_numbering][count for //0avg//1variance//2std] //need initialize
    	  	for (int pp = 0; pp < 50 ; pp ++)
    	  	{
       	  	for (int qq = 0; qq < 3 ; qq ++)
       	  	{
       	  	  subregcnt[pp][qq] = 0;
       	  	  subregvolsum[pp][qq] = 0.0;
 	  	   	  	for (int rr = 0; rr < 3 ; rr ++)
         	  	{
         	  	  subregavg[pp][qq][rr] = 0.0;    	  	  
            	}
      	  	}
     	  	}
     	  	
     	  	subregavga0 = 0.0;
          subregavga1 = 0.0;
          subregavgacnt = 0;
     	  	subregvolsuma = 0.0;
    	  	
        		while(fin.get(ch))
        		{
                  			if (ch != '\n') 
                  			{
                  				//tmpchar[count] = ch;
                  				count = count+1;
                  				cnumdata.push_back(ch);
                  			}
                  			if (ch == ' ') 
                  			{
                          //  for ( i = count; i<20 ; i++)
                          //  {
                          //    tmpchar[i] = ' ';
                          //  }
                            
                            if (j == 1)
                            {
                              if (ncolforspc == -1) 
                              {
                                f_dt = (float)atof(cnumdata.c_str()); //routine finding f_dt
                                fout << f_dt*(float)j << " "; // here to put timesteps instead of number of lines
                               }
                            }
                            
                            
                  			    count = 0;
                  			                      			    


 /*                  		      	    
if (spicescount == targetmolecule && ncolforspc != -1) 
cout << spicescount[!not] << " == " << coltitlecount <<"/"<< ncolforspc << "-" << j << "-----  " << tmpchar << "\n" ;                        		      

  tmpchar  ==> data
  ncolforspc ==> element numbering;

 ** if ncolforspec is listed in the xyout_nelement
  -> add  to the datasum, put x or y corrd to cord, inside [] should be cmap[]
   number add should be int or volumes as well.
   -> cord array numbering is order of coordinate nmbering !!

      int isxsort;
	    int isysort;
	    float xyout_cord[2000];
 	    float xyout_datasum[2000];
	    float xyout_volumesum[2000];
 	    float xyout_numberadd[2000];

	    int nselected;
	    int xyout_cmap[2000];
 	    int xyout_nelement[2000];
 	    float xyout_x[2000];
 	    float xyout_y[2000];
 	    float xyout_volume[2000];
 	    
	    float xyout_varsum[2000];
 	    

 	    */
////////////////////////////one line reading start ////////////////////////////////////////////////////////////////////////////////////
                        		      if (spicescount == targetmolecule && ncolforspc != -1)  //ncolforspc is element number, ncolforspec start from -1 since 1st column is time
                        		      {
                        		       
                        		       
                        		       
                        		       
                        		       
                        		       
                        		       
//                        		            	if (isprintscreen == 1) cout << spicescount << " == " << coltitlecount <<"/"<< ncolforspc << "-" << j << "-----  " << tmpchar << "\n" ;
                        		            	if (isprintscreen == 1) cout << spicescount << " == " << coltitlecount <<"/"<< ncolforspc << "-" << j << "-----  " << cnumdata << "\n" ;
                        		            	
                        		            	if (isallregavg == 1) //accmulate data for avg,var and std. ncolforspc is element number
                        		            	{
                                            //string regionheaderinfo[4000]; //max sub region number 50 //3000 element max
                                            //float meshvolume[4000];
                                            //string subregion[50]; //max sub region number 50
                                            //int subregioncount;
                                            //int isallregavg;
                                            //subregion list
                                            //0 dendrite1
                                            //1 dendrite2
                                            //2 dendrite3
                                            //3 neck
                                            //4 head
                                            //5 psd
                        		            	  //float subregavg[50][3][3]; //[subreg_name][0all_1:cyt_2:submem][//0avg//1variance//2std]   
                                            //int subregcnt[50][3]; //[subreg_name_numbering][count for //0all//1dend//2cytosol] //need initialize

                                            tmpvar = (float)atof(cnumdata.c_str());
                                            
                                            //need code for total region
                                            //
                                            
                                                //float subregavga0;
                                                //float subregavga1;
                                                //int subregavgacnt;
                                                //float subregvolsuma;
                                                        if(isdatanumberofmolecule==1) //use concentration for var and std, for avg.. need molecule number and volumesum
                                                        {
                                                          subregavga0 += tmpvar/divnptonM; //avg
                                                          subregavga1 += (tmpvar/divnptonM)*(tmpvar/divnptonM)/(meshvolume[ncolforspc]*meshvolume[ncolforspc]); //var
                                                          subregavgacnt +=1;
                                                          subregvolsuma +=meshvolume[ncolforspc];                                                        
                                                        }
                                                        else //data is concentration
                                                        {
                                                          subregavga0 += tmpvar*meshvolume[ncolforspc]; //avg
                                                          subregavga1 += tmpvar*tmpvar; //var
                                                          //subregavg[m][2][2] -> std will be from var
                                                          subregavgacnt +=1;
                                                          subregvolsuma +=meshvolume[ncolforspc];                                                        
                                                        }
                                                        
                                            
                                            for(int m=0; m < subregioncount ; m++)
                                              {
                                                found = regionheaderinfo[ncolforspc].find(subregion[m]);//compare colheaddata with subregion list
                                                //cout <<  regionheaderinfo[ncolforspc] <<" " <<  subregion[m] << "" << found << "\n";
                                                if (found !=string::npos) //find maching subregion from list
                                                {

                                                      //submembrane data accum  [m][2]
                                                      found = regionheaderinfo[ncolforspc].find("submembrane");
                                                      if (found !=string::npos) //find submembrane
                                                      {
                                                        if(isdatanumberofmolecule==1) //use concentration for var and std, for avg.. need molecule number and volumesum
                                                        {
                                                          subregavg[m][2][0] += tmpvar/divnptonM; //avg
                                                          subregavg[m][2][1] += (tmpvar/divnptonM)*(tmpvar/divnptonM)/(meshvolume[ncolforspc]*meshvolume[ncolforspc]); //var
                                                          //subregavg[m][2][2] -> std will be from var
                                                          subregcnt[m][2] +=1;
                                                          subregvolsum[m][2] +=meshvolume[ncolforspc];                                                        
                                                        }
                                                        else //data is concentration
                                                        {
                                                          subregavg[m][2][0] += tmpvar*meshvolume[ncolforspc]; //avg
                                                          subregavg[m][2][1] += tmpvar*tmpvar; //var
                                                          //subregavg[m][2][2] -> std will be from var
                                                          subregcnt[m][2] +=1;
                                                          subregvolsum[m][2] +=meshvolume[ncolforspc];                                                                                                                
                                                        }
                                                      }
                                                      //submembrane data accum  [m][2] end

                                                      
                                                      //cytosole data accum [m][1]
                                                      found = regionheaderinfo[ncolforspc].find("cytosol");
                                                      if (found !=string::npos) //find cytosole
                                                      {
                                                        if(isdatanumberofmolecule==1) //use concentration for var and std, for avg.. need molecule number and volumesum
                                                        {
                                                          subregavg[m][1][0] += tmpvar/divnptonM; //avg
                                                          subregavg[m][1][1] += (tmpvar/divnptonM)*(tmpvar/divnptonM)/(meshvolume[ncolforspc]*meshvolume[ncolforspc]); //var
                                                          //subregavg[m][1][2] -> std will be from var
                                                          subregcnt[m][1] +=1;
                                                          subregvolsum[m][1] +=meshvolume[ncolforspc];                                                        
                                                        }
                                                        else //data is concentration
                                                        {
                                                          subregavg[m][1][0] += tmpvar*meshvolume[ncolforspc]; //avg
                                                          subregavg[m][1][1] += tmpvar*tmpvar; //var
                                                          //subregavg[m][1][2] -> std will be from var
                                                          subregcnt[m][1] +=1;
                                                          subregvolsum[m][1] +=meshvolume[ncolforspc];                                                                                                                
                                                        }
                                                      }
                                                      //cytosole data accum [m][1] end
                                                      
                                                        //alldata accum [m][0]
                                                        if(isdatanumberofmolecule==1) //use concentration for var and std, for avg.. need molecule number and volumesum
                                                        {
                                                          subregavg[m][0][0] += tmpvar/divnptonM; //avg
                                                          subregavg[m][0][1] += (tmpvar/divnptonM)*(tmpvar/divnptonM)/(meshvolume[ncolforspc]*meshvolume[ncolforspc]); //var
                                                          //subregavg[m][0][2] -> std will be from var
                                                          subregcnt[m][0] +=1;
                                                          subregvolsum[m][0] +=meshvolume[ncolforspc];                                                        
                                                        }
                                                        else //data is concentration
                                                        {
                                                          subregavg[m][0][0] += tmpvar*meshvolume[ncolforspc]; //avg
                                                          subregavg[m][0][1] += tmpvar*tmpvar; //var
                                                          //subregavg[m][0][2] -> std will be from var
                                                          subregcnt[m][0] +=1;
                                                          subregvolsum[m][0] +=meshvolume[ncolforspc];                                                                                                                
                                                        }
                                                        //alldata accum [m][0] end
                                                }
                                              }
                                          }//if (isallregavg == 1)  end
                        		            	
                        		            	
                        		            	//////////////////////////////////////////////// x,y sorting block
                        		            	if (isxsort == 1 || isysort == 1)
                        		            	{
                              		            	for (int i =0; i<nselected ; i++)
                              		            	{
                              		            	    if (ncolforspc == xyout_nelement[i])
                              		            	      {
                              		            	        
                                                            if( isdatanumberofmolecule == 0) //for concentration
                                                            {
                                                              //xyout_datasum[xyout_cmap[i]] += xyout_volume[i]*(float)atof(tmpchar);
                                                              tmpvar = (float)atof(cnumdata.c_str());
                                                              xyout_datasum[xyout_cmap[i]] += xyout_volume[i]*tmpvar;
                                                              if(isaverage == 1) xyout_varsum[xyout_cmap[i]] += tmpvar*tmpvar; 
                                                            }
                                                            if( isdatanumberofmolecule == 1) //for number of molecules
                                                            {
                                                              //xyout_datasum[xyout_cmap[i]] += (float)atof(tmpchar);
                                                              tmpvar = (float)atof(cnumdata.c_str());
                                                              xyout_datasum[xyout_cmap[i]] += tmpvar/divnptonM; //for nM output for averaging
                                                              if(isaverage == 1) xyout_varsum[xyout_cmap[i]] += (tmpvar/divnptonM)*(tmpvar/divnptonM)/(xyout_volume[i]*xyout_volume[i]); //for nM output
                                                            }
                                                            
                                                            //where I need put y~here
                                                            if (isysort == 1) xyout_cord[xyout_cmap[i]] = (float)xyout_y[i] ;
                                                            if (isxsort == 1) xyout_cord[xyout_cmap[i]] = (float)xyout_x[i] ;
                                                            
                            		            	         	    xyout_numberadd[xyout_cmap[i]] += 1.0f;
                            		            	         	    xyout_volumesum[xyout_cmap[i]] += xyout_volume[i];
                              		            	      }
                              		            	}
                        		            	}//if (isxsort == 1 || isysort == 1)
                        		            	////////////////////////////////////////////////sorting block - end                        		            	
                        		      }
                  			    //	if (spicescount == targetmolecule && ncolforspc != -1) nrddata[ncolforspc][j] = atof(tmpchar);
                   			    


//writing outputdata   
//           if (spicescount == targetmolecule && ncolforspc != -1) fout << atof(tmpchar)<< " ";
             if (spicescount == targetmolecule && ncolforspc != -1) fout << atof(cnumdata.c_str())<< " ";
 	    	     cnumdata.clear(); //clear read data piece after file write 

                  		      coltitlecount += 1;
                  	        ncolforspc +=1; // export to file with put space ' ' here

                            if (ncolforspc == nelement) {ncolforspc = 0; spicescount += 1;}

                  			}//if (ch == ' ') end
                  			
                  			
                  			
                  			if (ch == '\n') 
                  			{ 
                  			  fout << "\n";
                  			  break; 
                  			}
	        	}//while(fin.get(ch)) end

////////////////////////////one line reading end////////////////////////////////////////////////////////////////////////////////////	        	
////////////////////////////postprocessing starts after one line read////////////////////////////////////////////////////////////////////////////////////	        	
     		            	if (isallregavg == 1) //postprocess for avg,var and std. ncolforspc is element number
     		            	{
     		            	  //use sout
     		            	  if (j == 0)
     		            	  {
       		            	  sout << "Time" << " ";
       		            	  for (int p =0; p <subregioncount ; p++ )
       		            	  {
//       		            	    Time Ave_dend1 Stdev_dend1 Ave_submembrane_dend1 Stdev_submembrane_dend1 Ave_cytosol_dend1 Stdev_cytosol_dend1
       		            	    sout << molnameinput << "_AVG_"<< subregion[p] << " ";
      		            	    //sout << "VAR_"<< subregion[p] << " ";
       		            	    sout << "STD_"<< subregion[p] << " ";
       		            	    if (subregcnt[p][2] > 0) //submembrane
       		            	    {
       		            	    sout << molnameinput << "_AVG_SM_"<< subregion[p] << " ";
      		            	    //sout << "VAR_submembrane_"<< subregion[p] << " ";
       		            	    sout << "STD_SM_"<< subregion[p] << " ";
       		            	    }
       		            	    if (subregcnt[p][1] > 0) //cytosol
       		            	    {
       		            	    sout << molnameinput << "_AVG_CT_"<< subregion[p] << " ";
      		            	    //sout << "VAR_cytosol_"<< subregion[p] << " ";
       		            	    sout << "STD_CT_"<< subregion[p] << " ";
       		            	    }
       		            	  }
    		            	    //sout << molnameinput <<"_AVG_TOTAL VAR_TOTAL STD_TOTAL";
    		            	    sout << molnameinput <<"_AVG_TOTAL STD_TOTAL";
       		            	  sout <<"\n";
       		            	  //end writing column header

       		            	  cout << "Subregion number"<< "\n";
       		            	  for (int pp =0; pp <subregioncount ; pp++ )
       		            	  {
       		            	  cout << subregion[pp]<< ":"<< subregcnt[pp][0] << " ";
      		            	  cout <<"  cytosol:" << subregcnt[pp][1] << " ";
       		            	  cout <<"  submembrane:" << subregcnt[pp][2] << " ";
       		            	   cout <<  "\n";
       		            	  }

     		            	  }//if (j == 0)
     		            	  
     		            	  //no need else, just postprocess number data here
     		            	  
     		            	                          //string regionheaderinfo[4000]; //max sub region number 50 //3000 element max
                        //float meshvolume[4000];
                        //string subregion[50]; //max sub region number 50
                        //int subregioncount;
                        //int isallregavg;
                        //subregion list
                        //0 dendrite1
                        //1 dendrite2
                        //2 dendrite3
                        //3 neck
                        //4 head
                        //5 psd
                     	  //float subregavg[50][3][3]; //[subreg_name][0all_1:cyt_2:submem][//0avg//1variance//2std]   
                        //int subregcnt[50][3]; //[subreg_name_numbering][count for //0all//1dend//2cytosol] //need initialize
                        // subregvolsum[m][0] +=meshvolume[ncolforspc];                                                                                
                           
//                         sout <<  (float)xyout_datasum[i]/xyout_volumesum[i] << " "; //final output is always concentration
//                         tmpvar = (float)xyout_varsum[i]/(float)xyout_numberadd[i]-pow((float)xyout_datasum[i]/xyout_volumesum[i],2.0f);
//                         if (isaverage == 1) sout << tmpvar  <<" "<< sqrt(tmpvar) <<" "; //variance,std

                          sout << f_dt*(float)j << " ";  // here to put another timesteps than number of lines 
                          
                          float stmpvar;
     		            	    for (int p =0; p <subregioncount ; p++ )
       		            	  {
                              sout << (float)subregavg[p][0][0]/subregvolsum[p][0] << " ";; //average
                              stmpvar = (float)subregavg[p][0][1]/(float)subregcnt[p][0] - pow((float)subregavg[p][0][0]/subregvolsum[p][0],2.0f);
                              //sout << stmpvar << " ";; //VAR
                              sout << sqrt(fabs(stmpvar)) << " "; //std
       		            	    if (subregcnt[p][2] > 0) //submembrane
       		            	    {
                              sout << (float)subregavg[p][2][0]/subregvolsum[p][2] << " ";; //average
                              stmpvar = (float)subregavg[p][2][1]/(float)subregcnt[p][2] - pow((float)subregavg[p][2][0]/subregvolsum[p][2],2.0f);
                              //sout << stmpvar << " ";; //VAR
                              sout << sqrt(fabs(stmpvar)) << " "; //std
       		            	    }
       		            	    if (subregcnt[p][1] > 0) //cytosol
       		            	    {
                              sout << (float)subregavg[p][1][0]/subregvolsum[p][1] << " ";; //average
                              stmpvar = (float)subregavg[p][1][1]/(float)subregcnt[p][1] - pow((float)subregavg[p][1][0]/subregvolsum[p][1],2.0f);
                              //sout << stmpvar << " ";; //VAR
                              sout << sqrt(fabs(stmpvar)) << " "; //std
       		            	    }
       		            	  }
       		            	  
       		            	                //float subregavga0;
                                                //float subregavga1;
                                                //int subregavgacnt;
                                                //float subregvolsuma;
                                                
                              sout << (float)subregavga0/subregvolsuma << " ";; //average
                              stmpvar = (float)subregavga1/(float)subregavgacnt - pow((float)subregavga0/subregvolsuma,2.0f);
                              //sout << stmpvar << " ";; //VAR
                              sout << sqrt(fabs(stmpvar)) << " "; //std
       		            	  
       		            	   sout <<  "\n";
     		            	  //no need else, just postprocess number data here - end
     		            	} //if (isallregavg == 1) end

	        	          if (isxsort == 1 || isysort == 1)
	        	          {
  	        	          //   cout <<  "\n ";

                              if (j == 0)
                              {
//                                 for (int i = 0; i<ncoord ; i++)
//                                 {
//                                  if(isaverage == 0) sout <<  i << " "; //coordinate number //do not print cause it is confusing since it is not sorted
//                                
//                              	 }
                                 //if(isaverage == 0) sout <<  "\n";
                                                                  
                                 for (int i = 0; i<ncoord ; i++)
                                 {
                                  if (isaverage == 0) sout <<  (float)xyout_cord[i] << " "; //coordinate x or y
                              	 }
                                  if(isaverage == 0) sout <<  "\n";

                                  if(isaverage == 1) sout <<  "Time  " << molnameinput <<"_Avg STD\n";
                              }
                        	 for (int i = 0; i<ncoord ; i++)
                           {
                            //sout <<  (float)xyout_datasum[i]/xyout_numberadd[i] << " ";
                            if (isaverage == 1) sout << f_dt*(float)j << " "; // here to change number of lines to timesteps
                            sout <<  (float)xyout_datasum[i]/xyout_volumesum[i] << " "; //final output is always concentration
                            tmpvar = (float)xyout_varsum[i]/(float)xyout_numberadd[i]-pow((float)xyout_datasum[i]/xyout_volumesum[i],2.0f);
                            //if (isaverage == 1) sout << tmpvar  <<" "<< sqrt(tmpvar) <<" "; //variance,std
                            if (isaverage == 1) sout << sqrt(fabs(tmpvar)) <<" "; //variance,std
                            //cout <<  (float)xyout_datasum[i]<< " ";
                            // cout <<  (float)xyout_numberadd[i] << " ";
                         	 }
                           sout <<  "\n";
                      }//  if (isxsort == 1) -end
              
                           for (int i = 0; i<ncoord ; i++)
                           {
                               xyout_cord[i]=0.0f;
                               xyout_datasum[i]=0.0f;
                               xyout_numberadd[i]=0.0f;
                               xyout_volumesum[i]=0.0f;
                               xyout_varsum[i]=0.0f;
                           }

////////////////////////////postprocessing ends after one line read////////////////////////////////////////////////////////////////////////////////////	        	                             
        	              
      	}// for (j = 0; j < totalsteps ; j++)end

	/////////////////////////////////////////////column Number Data reading end /////////////////////////////////
	///////////////////////////////////////////// Write target molecules data /////////////////////////////////
/*
	cout << "read number data file - done" << "\n";
	cout << "write number data file" << "\n";
        for (k = 0; k < totalsteps ; k++)
        { 
		cout << "step" << k << "\n";
		fout << k << " ";
		for (i = 0; i < nelement; i++)
		{
			fout << nrddata[i][k] << " ";
			//fout << "data" << i << " ";
		}
		
		fout << "\n";
	}
*/

  sout.close();
	fin.close();
	fout.close(); 
	cout << "write number file - done" << "\n";
	
	if (isaverage == 0 && isxsort==0 && isysort==0 && isallregavg == 0) cout << "Check ["<< outfile <<"] for extracted molecule concentration data!" <<'\n';
 	if (isaverage == 0 && isxsort==1 && isallregavg == 0) 	cout << "Check ["<< nrdpostfilename <<"] for spatial average!" <<'\n';
 	if (isaverage == 0 && isysort==1 && isallregavg == 0) 	cout << "Check ["<< nrdpostfilename <<"] for spatial average!" <<'\n';
 	if (isaverage == 1 && isxsort==1 && isallregavg == 0) 	cout << "Check ["<< nrdpostfilename <<"] for selected sub-region average!" <<'\n';
 	if (isallregavg == 1) cout << "Check ["<< nrdpostfilename <<"] for All sub-region average!" <<'\n';

  cout << "ReadData() - done!\n";
//  cout << "Deleting DUMP files...\n\n"; //
  remove("NRDpost_DUMP.txt");
  remove("NRDPost_DUMP1.txt");
  
  
	///////////////////////////////////////////// Write target molecules data end /////////////////////////////////
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CodeTest()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CodeTest()
{
/*
	char *filename;
	int number;
	number = 20;
    double mx;
	cout.precision(15);

	filename = "test.txt";
	mx = 0.12123123442;

	ofstream fout(filename);
	fout.precision(15);
	number=number+15;

	fout << number << ".txt\n";
	fout << mx << "\n";

	fout.close(); 

	ifstream fin(filename);
	fin.precision(15);

	char ch;
	char outfile[7];
	char xval[20];
	double xvald;
	int count;
	count = 0;
	while(fin.get(ch))
	{
	if (ch == '\n') {break;}
	outfile[count] = ch;
	count = count+1;
	}
	count = 0;
	while(fin.get(ch))
	{
	if (ch == '\n') {break;}
	xval[count] = ch;
	count = count+1;
	}

	//fin.getline(outfile,80);
	//fin.getline(xval,80);

	fin.close();

	cout << "Output file name : " << outfile << "\n";
	xvald = atof(xval);

	ofstream nout(outfile);
	nout.precision(15);

	nout << "created file\n";
	nout << xvald << "\n";
	nout.close();

	//int transorm
	char *s;
	double x;

	s = "  -2309.123456789123456-15";
	x = atof(s);
	cout << s << "\n" << x <<"\n";
	cout << "test" << "\n";
	//int transform
	cout << "\n";
	cout << "\n";
*/

}
