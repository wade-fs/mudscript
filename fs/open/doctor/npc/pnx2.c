// fire phoenix---made by nike

#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIR + "赤羽火鳳" + NOR, ({"fire phoenix","phoenix","pnx"}) );
    set("race", "野獸");
    set("title",HIY + "瀧山鎮派聖獸" + NOR);
    set("long", "一隻羽毛非常美麗的火鳳凰，是瀧山派的
鎮派聖獸，你可以嘗試拔(pluck)牠的羽毛(feather)！\n");
     set_temp("apply/attack",550);
     set_temp("apply/damage",550);
     set_temp("apply/move",550);
    set("limbs", ({ "鳳喙","鳳爪","鳳身","鳳翅","鳳尾" }) );
    set("age", 500);
    set("combat_exp", 5000000);
    set("max_kee", 30000);
    set("kee", 30000);
    set("max_gin", 30000);
    set("gin", 30000);
    set("max_sen", 30000);
    set("sen", 30000);
    set("attitude", "peaceful");
    set_skill("parry", 500);
    set_skill("unarmed", 500);
    set_skill("dodge", 500);
    set_skill("move", 500);
    set("chat_chance", 4);
    set("chat_msg", ({
         "咕～咕～嘓～嘓～咕～咕～嘓～～～\n",
    }));
    setup();
}
void init()
{
    add_action("do_pluck","pluck");
    add_action("do_kill","kill");
    add_action("do_kill","fight");
}
int do_pluck(string arg)
{
    object me, ob, fea, pnx;
    int kar, spi;

    me = this_player();
    ob = this_object();
    kar = me->query_kar()*2;
    spi = me->query_spi()*2;
    spi = kar+spi;
    if(spi >= 80)
    spi = 80;

    if(!arg || arg != "feather") return 0;
    if(me->query("doctor/get_key",1))
{
    if(me->query("doctor/get_fea",1))
{
	message_vision(RED + "$N貪心的想再拔第二次...不料卻被" + HIR + "赤羽火鳳"NOR+RED"給發覺......\n" + NOR, me);
	pnx = new("/open/doctor/npc/pnx");
	pnx->move(environment(me));
	pnx->kill_ob(me);
	return 1;
}
    if(random(100) > spi)
{
	message_vision(RED + "$N偷偷的靠近" + HIR + "赤羽火鳳"NOR+RED"......\n" + NOR, me);
	message_vision(HIB + "$N成功\的將" + HIR + "赤羽火鳳"NOR+HIB"的尾羽給拔到手了！\n" + NOR, me);
	me->delete("get_key");
	me->set("get_fea",1);
	fea = new("/open/doctor/obj/feather");
	fea->move(me);
	return 1;
}else{
	message_vision(RED + "$N偷偷的靠近" + HIR + "赤羽火鳳"NOR+RED"......\n" + NOR, me);
	message_vision(MAG + "$N的動作太大，竟然被" + HIR + "赤羽火鳳"NOR+MAG"給發覺了！\n" + NOR, me);
	pnx = new("/open/doctor/npc/pnx");
	pnx->move(environment(me));
	pnx->kill_ob(me);
	destruct(ob);
	return 1;
    }
  }
}
int do_kill(string arg, object me)
{
    if(arg == "fire phoenix" || arg == "phoenix" || arg == "pnx")
{
	message_vision(RED + "$N這個笨蛋想吵醒牠嗎？\n" + NOR, me);
	return 1;
  }
}
