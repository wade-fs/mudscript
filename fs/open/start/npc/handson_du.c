// handson by anmy 97/12/26 for new year's quest
#include <ansi.h>
#include "../start.h"
 
inherit NPC;

void create()
{
	set_name("杜三少", ({"handson du","du" }) );
	set("gender", "男性");
        set("nickname", HIC + "京城第一帥" + NOR);
	set("age", 20);
	set("long","你看到一位帥哥正在你的眼前,但是他似乎正在煩惱該送什麼給女友。\n");
        set("per", 40);
	set("str", 25);
	set("con", 20);
	set("combat_exp", 500000);

	setup();
}

int accept_fight(object me)
{
	return
notify_fail("杜三少說：這位"+RANK_D->query_respect(me)+"別開我玩笑了好嗎？\n");
}

int accept_object(object who , object item)
{
	if( item->query("id")=="flower" ) {

tell_object(who,"杜三少痛哭流涕的說：謝謝你了！幫我買來要送女友的花~\n");
                if( !who->query("quests/happy") &&
                           who->query_temp("flower")==1 )
                    {		
     who->add("potential", 20000);

tell_object(who,HIY + "杜三少瀟撒的走到你的面前, 在你的面前親吻了一下\n" + NOR);
tell_object(who,HIR + "你只覺得臉好像紅通通的, 一種甜蜜的感覺油然而生\n" + NOR);
tell_object(who,HIY + "杜三少輕聲的在你耳邊說著: 這是一點小謝禮,有緣再見囉\n" + NOR);
tell_object(who,HIW + "你忽然覺得全身的氣力上升了許\多..\n" + NOR);

			who->set("quests/happy", 1);
		}
}
}
