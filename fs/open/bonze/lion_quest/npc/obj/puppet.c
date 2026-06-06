//作為技能mob-needle.c 的效果觸發物品
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIM"魔偶娃娃"NOR, ({ "puppet","p" }) );

        set("unit", "尊");
        set("long", "看起來像是一個普通的洋娃娃。\n");
        set_weight(1000);
        set("value",0);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_auc",1);
        set("no_give",1);
        set("no_steal",1);
        set("no_save",1);
}

void init()
{
	this_player()->set_temp("ma-needle",1); //mob-needle的技能mark之一
	this_player()->set_temp("fire_tooth",1); //mob-needle的技能mark之一
	set_heart_beat(1); //設定為一次的心跳
	::init();
}