#include <ansi.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
void create() { seteuid(getuid());}
int main(object me,string arg)
{
        string name1,name2;
        object source,target;

        if(wiz_level(me) <=5) return 0;

        if(!arg) return notify_fail("cp_user 想要被複制的id 新id.\n");

        if(sscanf(arg,"%s %s",name1,name2)!=2)
          return notify_fail("cp_user 想要被複制的id 新id.\n");

        source=find_player(name1);
        if(!source)
          source= FINGER_D->acquire_login_ob(name1);
        if(!source)
          return notify_fail("沒有 "+name1+" 這個玩家!!\n");

        target=find_player(name2);
        if(!target)
          target= FINGER_D->acquire_login_ob(name2);
        if(!target)
          return notify_fail("沒有 "+name2+" 這個玩家!!\n");

        source->set("id",name2);
        source->set("bss/cp_user",1);
        source->save();
        if(!find_player(name1))
        destruct(source);
        else{        
          if(source->query("id") != name1){
            source->set("id",name1);
            source->delete("bss/cp_user");
          }
        }
        if(find_player(name2))
          tell_object(target,sprintf("user 轉換完成, 你必須要重新連入才是%s\n",name1));
        destruct(target);
        write("複制完成!!\n");
        return 1;
}
int help(object me)
{
        if(!wizardp(me)) return 0;
        write(@HELP
指令格式: cp_user 被複制的id 新id

可以複制玩家檔到另一個char上
請注意,被複制的 id and 新的id都必須已經連進來過才會生效
HELP
        );
        return 1;
}
