#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
        object *enemy;
        enemy = me->query_enemy();
         if( !me->is_fighting())
         return notify_fail("只能在戰鬥中使用。\n");
if(me->query("class")!="swordsman")
return notify_fail("不是劍士不能用喔。\n");
if(me->query("swordskill/allowdiesword")!=1)
return notify_fail("你啥都不會, 想用什麼??。\n");
        enemy = me->query_enemy();
        target = enemy[random(sizeof(enemy))];
        if( me->query("force") < 1000 )
        return notify_fail("你的內力不夠。\n");
        message_vision(HIR + "$N開始吸收天地之氣，只見無數光點由四面八方向他聚集。\n\n" + NOR,me);
        message_vision(HIG + "$N在吸收完天地之氣後，全身散發出駭人劍氣，其對手受劍氣牽制，全身上下無法動彈，只能靜觀這無比震撼的一擊。\n\n" + NOR,me);

          me->do_command("gt --劍聖奧義---萬劍俱滅--");
        message_vision(HIY + "只見$N目光一閃 : 看我的『" + HIB + "---鬼哭神號，萬劍俱滅---" + HIY + "』。\n\n" + NOR,me);
        message_vision(HIC + "聚集$N身邊無數的光點忽然換化為無數劍芒將其對手完全籠罩，並一一破體而過。\n\n" + NOR,me);
        message_vision(HIM + "在受到無數劍氣貫穿之後，你的對手似乎無法相信眼前所發生的事物，但其再也無法做出任何反應了。\n" + NOR,me);
        target->set_temp("last_damage_from",me);
        target->die();
        message_vision(HIR + "在使出此絕招之後…$N已耗盡全身力氣，漸漸的，你以無法支撐你的身體……\n……\n…\n…\n " + NOR,me);
        me->die();
// 沒開放的東西竟有人用  嘿  抓人砍檔了 by swy
log_file("mblade/usediesword",sprintf("%s(%s) 使用沒開放的 diesword on %s\n",me->query("name"),me->query("id"),ctime(time())));
return 1;
}

