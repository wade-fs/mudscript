#include <ansi.h>
int main(object me,string arg)
{
    string path,type,st;
    string *files;
    int j;
    if(!arg) return notify_fail("你要在玩家的檔案裡面找什麼字串？\n");
    if(sscanf(arg,"%s %s",type,st) != 2)
        return notify_fail("使用方法為：fgrep [alias/autoload/dbase/skills] 欲搜尋的字串 \n");

    foreach(string a in "abcdefghijklmnopqrstuvwxyz")
    {
        string f;
        mixed m;
        int i;
        j=0;
reset_eval_cost();
        path = sprintf("/data/user/%c/",a);
        files = get_dir(path, -1);
        foreach(string *file in files)
        {
            f = sprintf("%s%s",path,file[0]);
            foreach(string *line in explode(read_file(f) ,"\n"))
            {
                if(line[0] == "#") continue;
                m = ([]);
                switch(type)
                {
                case "skills":
                    sscanf(line,"skills %s",m);
                    break;
                case "dbase":
                    sscanf(line,"dbase %s",m);
                    break;
                case "autoload":
                    sscanf(line,"autoload %s",m);
                    break;
                case "alias":
                    sscanf(line,"alias %s",m);
                    break;

                default:
                    break;
                }
                if(!sizeof(m)) continue;
                i = -1;
                j = -1;
                while( (i = strsrch(m[j..<1],st)) > 0  ){
                    int i_min,i_max;
                    j += i;
                    if((i_min = j - 15 )< 0 ) i_min = 0;
                    i_max = j + sizeof(st)+15;
                    if(i_max   > sizeof(m) ) i_max = sizeof(m);

                    printf("於 %s 中找到 %s 其資料為： ... %s ...\n",file[0][0..<3],st,HIY + m[i_min..i_max]+ NOR);
                    j +=4;
                }

                continue;

            }
        }
    }

    return 1;
}
