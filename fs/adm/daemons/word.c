#include <ansi.h>
string line1(string);
string line2(string);
string line3(string);
string line4(string);
string random_replace(string);
string paper(string arg)
{
        int j,i;
        string str="";
        
        for(j=0;j<strlen(arg);j++)
        {
        str += line1(arg[j..j]);
        }
        str += "\n";
        for(j=0;j<strlen(arg);j++)
        {
        str += line2(arg[j..j]);
        }
        str += "\n";
        for(j=0;j<strlen(arg);j++)
        {
        str += line3(arg[j..j]);
        }
        str += "\n";
        for(j=0;j<strlen(arg);j++)
        {
        str += line4(arg[j..j]);
        }
return  HIC + random_replace(str)+"\n" + NOR;
}
string random_replace(string str)
{
  int rand = random(sizeof(str)*5/100)+2;
  for(int i = 0 ; i < rand ; i++)
  {
    int rand2 = random(sizeof(str)-4);

    while(!is_chinese(str[rand2..rand2+1]) || (str[rand2] == '\n' || str[rand2+1] == '\n' || str[rand2] == ' ' )) {

      rand2++;
    }
    if(rand2 >= sizeof(str)) continue;
    str[rand2] = '-';
    str[rand2+1]= '-';
  }
  return str;
}
string line1(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "  ┌┐  ";
        break;
        case 2:
        return "╭──╮";
        break;
        case 3:
        return "╭──╮";
        break;
        case 4:
        return "┌┐┐  ";
        break;
        case 5:
        return "┌──┐";
        break;
        case 6:
        return "╭──╮";
        break;
        case 7:
        return "┌──╮";
        break;
        case 8:
        return "╭──╮";
        break;
        case 9:
        return "╭──╮";
        break;
        case 0:
        return "╭──╮";
        break;
        }
}
string line2(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "┌╯│  ";
        break;
        case 2:
        return "╰─╮│";
        break;
        case 3:
        return "╰─╮│";
        break;
        case 4:
        return "│││  ";
        break;
        case 5:
        return "│┌─┘";
        break;
        case 6:
        return "│╭─╯";
        break;
        case 7:
        return "└─╮│";
        break;
        case 8:
        return "│╭╮│";
        break;
        case 9:
        return "│╭╮│";
        break;
        case 0:
        return "│╭╮│";
        break;
        }
}
string line3(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "  ││  ";
        break;
        case 2:
        return "╭╭─╯";
        break;
        case 3:
        return "╰─╮╮";
        break;
        case 4:
        return "│││  ";
        break;
        case 5:
        return "╰─╮╮";
        break;
        case 6:
        return "│╭╮│";
        break;
        case 7:
        return "   ／／ ";
        break;
        case 8:
        return "╭╭╮╮";
        break;
        case 9:
        return "╰─╮│";
        break;
        case 0:
        return "││││";
        break;
        }
}

string line4(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "└──┘";
        break;
        case 2:
        return "╰──╯";
        break;
        case 3:
        return "╰──╯";
        break;
        case 4:
        return "└┐┌┘";
        break;
        case 5:
        return "╰──╯";
        break;
        case 6:
        return "╰──╯";
        break;
        case 7:
        return "  └┘  ";
        break;
        case 8:
        return "╰──╯";
        break;
        case 9:
        return "╰──╯";
        break;
        case 0:
        return "╰──╯";
        break;
        }
}
