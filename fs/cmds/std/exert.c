// exert.c fixed by babe

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main( object me, string arg, int repeat )
{
  string force, tmp;
  int i, r;

  seteuid (getuid());

  if (!arg)
    return notify_fail ("要用內功\做什麼?\n");
  notify_fail ("內功\中沒有這種功\能。\n");
  arg = lower_case (arg);
  tmp = arg;
  if (sscanf (arg, "%s %d", arg, repeat) != 2)
    arg = tmp;
  if (repeat < 1) repeat = 1;
  else if (repeat > 10) repeat = 10;

  if (me->is_busy() || me->query_condition("force") > 0 )
    return notify_fail (BLU + "你一運氣用力, 發覺丹田中毫無內息。\n" + NOR);
  if (me->query_condition("no_power_e"))
    return notify_fail (HIM + "你感覺到體內有無數的氣勁亂流, 使你無法正常的使用內力。\n" + NOR);
	if (me->query_condition("block_sweat"))
    return notify_fail (HIM + "你體內真氣受到蒙汗藥的抑制，無法順利運行。\n" + NOR);
  if (me->query_temp("crazy"))
    return notify_fail (HIR + "你正陷入狂暴狀態, 無法控制內息流動。\n" + NOR);
  if ((me->query("food")<1 || me->query("water")<1) && userp(me)) {
    if (random(100) < 1) {
			me->receive_wound ("kee", me->query("age"));
      return notify_fail( RED + "你感覺又餓又渴, 一時之間無法控制真氣, 受到了內傷!" + NOR );
    }
    return notify_fail( BLU + "你感覺又餓又渴! 無法運氣!\n" + NOR );
  }

  if (stringp (force=me->query_skill_mapped("force") )) {
    for( i=0; i<repeat; i++ )
      if( SKILL_D(force)->exert_function( me, arg ) ) {
        r = 1;
//        if( random(300) < (int)me->query_skill( "force", 1 ) )
//          me->improve_skill( force, 1, 1 );
			}
			else if( SKILL_D("force")->exert_function( me, arg ) ) {
				r = 1;
//				if ( random(300) < (int)me->query_skill( "force", 1 ) )
//					me->improve_skill( "force", 1, 1 );
			}
    if (r == 1)
      switch(arg) {
        case "reseckee": {
        	i = me->query_temp("doTime");
          // with do
          if ((time() - i) < 10)
            break;
          // without do
          message_vision( CYN + "$N將體中的內力化成靈氣﹐使靈氣轉強。\n" + NOR, me ); break;
        }
			case "recover" :
				message_vision( CYN + "$N深深吸了" + chinese_number(repeat) + "口氣﹐臉色看起來好多了。\n" + NOR, me ); break;
			case "regenerate" :
				message_vision( CYN + "$N深深吸了" + chinese_number(repeat) + "口氣﹐手腳活動了幾下﹐整個人看起來有活力多了。\n" + NOR, me ); break;
			case "refresh" :
				message_vision( CYN + "$N略一凝神﹐吸了"+chinese_number(repeat)+"口氣﹐精神看起來清醒多了。\n" + NOR, me ); break;
			}
		return r;
	}

	return notify_fail( "尚未選擇(enable)所要使用的內功\。\n" );
}

int help (object me)
{
        write(@HELP
指令格式 : exert <功能名稱> [<施用對象>]
指令說明 :
           用內力進行一些特異功能﹐你必需要指定<功能名稱>﹐
         <施用對象>則可有可無。在你使用某一種內功的特異功
          能之前﹐你必須先用 enable 指令來指定你要使用的內功。

註﹕如果你改變自己的內功﹐你原本蓄積的內力並不能直接轉換過去﹐必須
    從 0 開始。
註﹕本命令可以重複使用, 如 10 exert refresh 或 exert refresh 10

其他參考 :
           help force 可得知一些大部分內功都有的功能﹐
           至於你所用的內功到底有沒有該功能﹐試一試或
           參考其他說明便知。
HELP
        );
        return 1;
}
