// junkwawa.c
//by casey..

#include <ansi.h>
#include <npc.h>
#include "/open/open.h"

inherit NPC;

void create()
{
        set_name("拾荒老頭", ({ "junk man" ,"man" ,"junk" }));
	set("force",3000);
        set("max_force",3000);
        set("attitude","peaceful");
        set("combat_exp",10);
        set("kee",30000);
        set("max_kee",30000);
        set("gin",30000);
        set("max_gin",30000);
        set("sen",30000);
        set("max_sen",30000);
        set("atman",30000);
        set("max_atman",30000);
        set("mana",30000);
        set("max_mana",30000);
        set("no_kill", 1);
        set("no_fight", 1);
        set("str",999);
        set("age", 70);
        set("long",
                "光著上身的一個小老頭﹐靠撿拾廢物維生﹐如果你願意幫助這樣一位\n"
                "老人過好一點的生活﹐或者是願意替辛苦的巫師們節省一點記憶體\n"
                "﹐請把你身上多餘的東西給他﹐可以得到一點的 civism。\n"
		"但是如果你打他的話﹐就會遭到非常嚴重的天譴唷。\n" );
        set("bounty/mortal sin", 5);
	set("random_move",1500);
        set("chat_chance", 2700);
	set("chat_msg",({
        (: random_move :),
        (: random_move :),
	(: command("get corpse") :),
	(: command("get all from corpse") :),
	(: command("get all") :),
        (: this_object(),"get all" :),

        }));
        
        setup();
}

void init()
{
	set_heart_beat(1);
}


void die()
{
        object ob, ob1, ob2, ob3, ob4, ob5, ob6, ob7;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;
	write(HIC + "拾荒老頭冷笑：「你也來陪葬吧。」\n" + NOR);
          ob->set("last_on", time());
          ob->set("last_from", query_ip_name(ob));
          ob->set_temp("last_damage_from", ob);
          ob -> die();

        destruct(this_object());
}




