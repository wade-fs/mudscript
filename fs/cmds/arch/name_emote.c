#include <ansi.h>
inherit F_CLEAN_UP;
void create(){ seteuid(getuid());}
int main(object me,string arg)
{
    mapping emote;
    string name;

    if(!arg) return notify_fail("name_emote emote 中文名稱\n");

    if(sscanf(arg,"%s %s",arg,name)!=2)
      return notify_fail("name_emote emote 中文名稱\n");

    emote=EMOTE_D->query_emote(arg);
    if(!mapp(emote)) return notify_fail("沒有這個emote!!\n");

    emote["short"]=name;
    printf("你設定%s的中文名稱為(%s)\n",arg,name);
    EMOTE_D->set_emote(arg, emote);
    write("ok.\n");
    return 1;
}
int help(object me)
{
        write(@HELP
指令格式: name_emote emote的英文名 emote的中文名

可以幫沒有中文名的emote命名, 也可以幫已經有中文名的emote改名
HELP
        );
        return 1;
}


