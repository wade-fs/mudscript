#include "/open/main/main.h"
#include <ansi.h>
inherit NPC;

string magic1();
string magic2();
void create()
{
        set_name("張通",({"Master taoist","master","taoist"}) );
        set("long",
        "負責教導初入道的道士們一些基礎的修行(verify)及
簡單的茅山術,想加入道士的行列請(join)。\n" );
        set("gender", "男性" );
        set("title",HIW + "～幻影～" + NOR + "玉磯道人");
        set("nickname","定乾坤");
        set("class","taoist");
        set("guild_master",1);

        set("combat_exp",1000000);
        set("max_mana",2000);
        set("mana",2000);
        set("max_kee",2000);
        set("kee",2000);
        set("force",1000);
        set("max_force",1000);
        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("force",50);
        set_skill("literate",70);
        set_skill("magic",50);
        set_skill("spells",60);
        set_skill("necromancy",60);
        map_skill("spells","necromancy");
        set_skill("magic",40);
        set_skill("gmagic",60);
        set_skill("move",80);
        set_skill("cure",50);
        set_skill("whip",60);
        set_skill("unarmed",40);
        set_skill("gwhip",60);
        map_skill("whip","gwhip");
        set("spells/stopmove/level",1);
        set("spells/feeblebolt/level",40);
        set("spells/missible/level",40);
        set("spells/explore/level",1);
        set("spells/manabody/level",1);
                                        
        set("chat_chance_combat",70);
        set("chat_msg_combat",({
        (:magic1:),
        (:magic2:),
        }));
        setup();
        carry_object("/open/tendo/obj/shoe")->wear();
        carry_object("/open/tendo/obj/hat")->wear();
        carry_object("/open/tendo/obj/robe")->wear();
        carry_object("/open/tendo/obj/whisk")->wield();

}


string magic1()
{
  command("cast feeblebolt");
  return "\n";
} 

string magic2()
{
  command("cast missible");
  return "\n";
}


int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW + "系統：戰鬥停止，$N回收中，。\n" + NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 13)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第十二層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第十三層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",13);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}


