#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
        object who,room;
        string out;

        seteuid(getuid(me));


        if(!arg) return help(me);
        if(me->query("sen") <50) return notify_fail("風之精靈聽不到你任何的呼喚!!\n");
        printf(HIC"你請風之精靈幫你找尋%s這個人!!\n"NOR,arg);
        who=find_player(arg);
        if(!who)
          who= FINGER_D->acquire_login_ob(arg);
        if(!who)
          return notify_fail("風之精靈回答你:在狂想的世界中似乎沒有這號人物的存在!!\n");
        if(wizardp(who) && !wizardp(me)){
          tell_object(who,sprintf(HIY"風之精靈告訴你:%s 這個人似乎在找你喔!!\n"NOR,geteuid(me)));
          return notify_fail("風之精靈回答你:在狂想的世界中似乎沒有這號人物的存在!!\n");
        }
        if(find_player(arg))
        tell_object(who,sprintf(HIY"風之精靈告訴你:%s 這個人似乎在找你喔!!\n"NOR,geteuid(me)));
        printf("
風之精靈回答你說: 找到 %s 這個人了
%s 的名字叫做: %s
%s 是一位 %s
",arg,arg,who->query("name"),arg,RANK_D->query_rank(who));
        if(me->query("family/master_id")==arg && find_player(arg)){
          room=environment(who);
          printf("%s(%s) 目前人在%s!!\n",who->query("name"),arg,room->query("short"));
        }
        else if(find_player(arg))
          printf("%s(%s) 目前在狂想的世界修鍊中!!\n",who->query("name"),arg);
        else
          printf("%s(%s) 目前在虛無漂渺間!!\n",who->query("name"),arg); 

        me->add("sen",-20);        
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : findman id
指令說明 :
           你可以請風之精靈幫你找找狂想中的人物, 不過需費一點神喔
           如果神不夠那風之精靈是聽不到你任何的呼喚的
HELP
    );
    return 1;
}


