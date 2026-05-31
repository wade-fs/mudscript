// gather.c

#include <ansi.h>

inherit SSERVER;
inherit F_GUILDCMDS;

int main(object me)
{
	if(me->query_temp("spe")==1)
		return notify_fail("你現在正在使用靈氣﹐不能修練。\n");
       if(!me->query("sec_kee"))
              return notify_fail("你的身上沒有任何靈氣。\n");
	if(me->query("atman")<10)
		return notify_fail("你的靈力不夠﹐無法修練靈氣。\n");
  if(me->query("sec_kee") == "dhyana")
    return notify_fail("佛法不是這樣練的。\n");

      message_vision(
          HIG + "$N體內真力貫入護身靈氣之中﹐使$N靈氣增強。\n" NOR,me);
	me->add("s_kee",me->query_spi()/10);
	me->add("atman",-10);
	if(me->query("s_kee")>me->query("max_s_kee")*2)
	{
//99/5/2加入殺意魔氣MAX的成長限制
                if (me->query("sec_kee") == "mkill")
                {//殺意魔氣以膽識為鍛鍊條件 膽識30*9＝270 MAX
	  if ( me->query("max_s_kee") >= (me->query_cor()*9))
	  {
	      tell_object(me,"你突然感到全身酸麻﹐似乎體內的靈氣已到極限。\n");
                        me->set("s_kee",me->query("max_s_kee"));
                        return 1;
                    }
	  me->add("max_s_kee",1);
                    me->set("s_kee",me->query("max_s_kee"));
                    tell_object(me,HIY "你的靈氣增強了﹗\n" NOR);
	  return 1;
                }
		if(me->query("max_s_kee")>=me->query_spi()*2+me->query("max_atman")/20)
		{
			tell_object(me,"你突然感到全身酸麻﹐似乎體內的靈氣已到極限。\n");
			me->set("max_s_kee",me->query_spi()*2+me->query("max_atman")/20);
			me->set("s_kee",me->query("max_s_kee"));
			return 1;
		}
		me->add("max_s_kee",1);
		me->set("s_kee",me->query("max_s_kee"));
		tell_object(me,HIY "你的靈氣增強了﹗\n" NOR);
	}
	return 1;
}
int help(object me)
{
  write( @HELP
 
這個指令是用來修練靈氣的﹐每次修練會減少實戰經驗。
 
HELP);
  return 1;
}
