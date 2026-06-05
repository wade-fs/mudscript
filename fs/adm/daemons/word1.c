#include <ansi.h>
mapping words = ([]);
string *files = ({
    "word3.txt",
    "word2.txt",
    "word1.txt"
    });
mapping read_word_file(string file);
string paper(string arg,string file);
void reset();
string file;
void create()
{
  seteuid(getuid());
  foreach(string f in files)
  {
    words[f] = read_word_file(
        "/adm/daemons/word/"+f);
  }
  reset();
}
array get_word(int length)
{
  string info ;
  string str="";
  string word = "";
  info = words[file]["choice"];
  for(int i = 0 ; i < length ; i++)
  {
    int rand = random(sizeof(info));
    str += info[rand..rand];
  }
  word = paper(str,file) ;
  return ({ str , file ,word});
}
string paper(string arg,string file)
{
  int j,i;
  mapping word;
  string str="";
  word = words[file];
    foreach(string a in arg)
    {
      str += "%-="+(word["x_ray"]*2)+"s ";
    }
  str = sprintf(str,
      word[arg[0..0]],
      word[arg[1..1]],
      word[arg[2..2]],
      word[arg[3..3]],
      word[arg[4..4]]);

  return  HIC + str+"\n" + NOR;
}
mapping read_word_file(string file)
{
  string * info; 
  mapping word;
  int x,y;
  info = explode(read_file(file),"\n");
  word = allocate_mapping(29);
  x = atoi(info[0]);
  y = atoi(info[1]);
  word["x_ray"] = x;
  word["y_ray"] = y;
  word["choice"] = info[2];
  for(int  i = 3 ; i < sizeof(info) ; i = i++)
  {
    int j;
    word[sprintf("%c",97+((i-3)/y))] = "";

    for(j = i ; j < i+ y; j++)
    {
      word[sprintf("%c",97+((i-3)/y))] += replace_string(info[j],"  ","　");
    }
    i = j;
  }
  return word;
  /*
     foreach(string a in "defghijklmnopqrstuvwxyz")
     {
     printf("%c = \n",a);
     printf("%-=6s\n",word[sprintf("%c",a)]);
     }*/
}
void reset()
{

  file = keys(words)[random(sizeof(words))];
}
