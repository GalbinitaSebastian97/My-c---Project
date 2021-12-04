
#include<fstream>
#include <experimental/filesystem>
#import "../Settings/settings.h"

bool checkExistanceFile(std::string nameOfFile, ){
    if(std::filesystem::exists(PATH + nameOfFile + EXTENSION)) return true;
    return false;
}

void createFileTxt(std::string nameOfFile){
    std::ofstream(PATH+nameOfFile+".txt");
}

std::string fullPath(std::string name){
    return PATH+name+EXTENSION;
}

int writeInText(std::string text, std::string nameOfFile){
    if(!checkExistanceFile(nameOfFile)) return 1;
    try{
        std::ofstream openfile;
        openfile.open(fullPath(nameOfFile),std::ios::app);
        if(openfile.is_open()) openfile<<text<<std::endl;
        openfile.close();
        }
    catch (int e){
        std::cout<<e;
    }

    return 0;
}

void deleteLastLine(const char* fileName, int n){   
  std::ifstream fin(fullPath(fileName));  
  std::ofstream fout;                
  fout.open(fullPath("temp"), std::ios::out); 
  
  char ch; 
  int line = 1;            
  while(fin.get(ch)) 
  {      
    if(ch == '\n') 
      line++; 
     
    if(line != n)     
      fout<<ch; 
  } 
  fout.close();  
  fin.close();
  std::string fileNameFullPath = fullPath(fileName);
  const char* fileNamec = fileNameFullPath.data();
  std::string v = fullPath("temp");
  remove(fileNamec);
  const char* temp = v.data();        
  rename(temp,fileNamec);
}

int main(){

    deleteLastLine("text3",6);
    



    return 0;
}