/* 網聚獎品，會增加每次戰鬥的經驗值和潛能 by whatup 2003/12/29 */
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"金"HIW"葫"HIB"蘆"NOR, ({ "gold gourd","gold","gourd" }) );
       
        set("unit", "個");
        set("long", "網聚獎品。此物將會增加所獲得的經驗值，不過他需要以血作祭，需要不停的嗜血(blood)。\n");
        set("value", 1);
            set("no_auc",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_put",1);
            set("no_drop",1);
            set("no_get",1);
            set("no_steal",1);
            set("no_save",1);

        setup();
}
void init()
{
    add_action("do_blood","blood");
}
int do_blood(string arg)
{
    object me = this_player();

    if(me->query("kee") < 200)
        return notify_fail("你的氣血過少無以為繼！\n");
    if(me->query_temp("addexp"))
        return notify_fail("他正在運行中！\n");

    me->set_temp("addexp",10);
    set_heart_beat(10);

        message_vision(BRED"一陣血氣自$N"BRED"身上衝破而出，$n"BRED"吸盡了$N"BRED"的血氣。\n"NOR,me,this_object());
    me->receive_damage("kee", 100 , me);
    set_name(BRED HIW "(泛著血光)" NOR HIY"金"HIW"葫"HIB"蘆"NOR, ({ "gold gourd","gold","gourd" }) );

    return 1;
}
void heart_beat()
{
    object me=environment();
if(me->is_fighting()) return ;
    if(!random(5))
    {
          me->receive_damage("kee", 100 , me);
message_vision(BRED"一陣血氣自$N"BRED"身上衝破而出，$n"BRED"吸盡了$N"BRED"的血氣。\n"NOR,me,this_object());          
    }
    if(me->query("kee") < 200)
    {
        me->delete_temp("addexp");
        set_heart_beat(0);
    }
}
int query_autoload()
{
      return 1;
}

