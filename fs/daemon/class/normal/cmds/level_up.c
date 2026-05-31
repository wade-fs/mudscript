//level_up.c by bss
//做個自己玩的, 先做成像賽亞人變身的形式, 以後若要給玩家的話須修改
#include <ansi.h>
inherit F_CLEAN_UP;

int godelay(object me);
int levelup(object me);
void create() { seteuid(getuid());}
int main(object me, string arg)
{
    int now_level,my_exp,max_level;

    if(!wizardp(me)) return 0;
    if(me->query_temp("leveluping")) return notify_fail("你正在集氣!!\n");
    my_exp=me->query("combat_exp");
    max_level=my_exp/1000000;
    if(max_level >10) max_level=10;
    now_level=me->query_temp("level/now_level");
    if(now_level==10) return notify_fail("你已經成長到極限了!!\n");
    message_vision(HIY"$N雙手握拳，半蹲馬步，開始不斷的提聚自己的鬥氣!!\n"NOR,me);
    now_level=now_level+1;
    me->set_temp("level/delay",now_level);
    me->set_temp("leveluping",1);
    call_out("godelay",3,me);
    return 1;
}

int godelay(object me)
{
    int delay,now_level;

    delay=me->query_temp("level/delay");
    if(delay){
      delay--;
      me->set_temp("level/delay",delay);
      message_vision(HIY"$N的鬥氣不斷竄升，氣勁不斷的在$N身旁翻滾著!!\n"NOR,me);
      call_out("godelay",3,me);
      return 1;
    }
    else{
      now_level=me->query_temp("level/now_level");
      now_level++;
      me->set_temp("level/now_level",now_level);
      call_out("levelup",1,me);
      return 1;
    }
}
int levelup(object me)
{
    int now_level;

    me->delete_temp("leveluping");
    now_level=me->query_temp("level/now_level");
    me->add("mpower",1);
//    me->add_temp("apply/attack",50*now_level);
    me->add_temp("apply/damage",100*now_level);
//    me->add_temp("apply/defense",25*now_level);
    me->add_temp("apply/armor",100*now_level);
    me->apply_condition("level_up",1);
    switch(now_level)
    {
      case 1:
        message_vision(HIY"$N大喝一聲，全身金光綻放，變身成為了超級賽亞人!!\n"NOR,me);
        me->set_temp("ride_name",HIY"超級賽亞人"NOR);
        break;
      case 2:
        message_vision(HIC"$N大喝一聲，全身藍光綻放，變身成為了超級賽亞人ＩＩ!!\n"NOR,me);
        me->set_temp("ride_name",HIC"超級賽亞人ＩＩ"NOR);
        break;
      case 3:
        message_vision(HIM"$N大喝一聲，全身紫光綻放，變身成為了超級賽亞人ＩＩＩ!!\n"NOR,me);
        me->set_temp("ride_name",HIM"超級賽亞人ＩＩＩ"NOR);
        break;
      case 4:
        message_vision(HBRED+HIW"$N大喝一聲，全身紅光白光不停的綻放，變身成為了超級賽亞人ＩＸ!!\n"NOR,me);
        me->set_temp("ride_name",HBRED+HIW"超級賽亞人ＩＸ"NOR);
        break;
      case 5:
        message_vision(HBRED+HIY"$N大喝一聲，全身紅光金光不停的綻放，變身成為了超級賽亞人Ｘ!!\n"NOR,me);
        me->set_temp("ride_name",HBRED+HIY"超級賽亞人Ｘ"NOR);
        break;
      case 6:
        message_vision(HBRED+HIC"$N大喝一聲，全身紅光藍光不停的綻放，變身成為了超級賽亞人ＸＩ!!\n"NOR,me);
        me->set_temp("ride_name",HBRED+HIY"超級賽亞人ＸＩ"NOR);
        break;
      case 7:
        message_vision(HBRED+HIM"$N大喝一聲，全身紅光紫光不停的綻放，變身成為了超級賽亞人ＸＩＩ!!\n"NOR,me);
        me->set_temp("ride_name",HBRED+HIM"超級賽亞人ＸＩＩ"NOR);
        break;
      case 8:
        message_vision(HBCYN+HIW"$N大喝一聲，全身藍光白光不停的綻放，變身成為了超級賽亞人ＸＩＩＩ!!\n"NOR,me);
        me->set_temp("ride_name",HBCYN+HIW"超級賽亞人ＸＩＩＩ"NOR);
        break;
      case 9:
        message_vision(HBCYN+HIY"$N大喝一聲，全身藍光金光不停的綻放，變身成為了超級賽亞人ＩＶ!!\n"NOR,me);
        me->set_temp("ride_name",HBCYN+HIY"超級賽亞人ＩＶ"NOR);
        break;
      case 10:
        message_vision(HBCYN+HIM"$N大喝一聲，全身藍光紫光不停的綻放，變身成為了超級賽亞人Ｖ!!\n"NOR,me);
        me->set_temp("ride_name",HBCYN+HIM"超級賽亞人ＩＶ"NOR);
        break;
      default:
        break;
    }
    return 1;
}

int help(object me)
{
    if(!wizardp(me)) return 0;
    write(@HELP

指令格式﹕cmd level_up

說明﹕這個指令可以聚集身上的鬥氣而成為超級賽亞人。

HELP
);
     return 1;
}
