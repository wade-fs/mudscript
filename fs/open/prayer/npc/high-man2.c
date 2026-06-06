//二徒弟
#include <command.h>
#include "/open/open.h"
 
inherit NPC;

void create()
{
    set_name("西域男子",({"man"}));
    set("gender", "男性");
    set("age",30);
    set("attitude","peaceful");
    set("long",@LONG

	他是廣成派的弟子, 排行第二!!精通鞭法!!

LONG);
 
    set("combat_exp",3000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",900);
    set("kee",900);
    set("max_force",900);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",60);
    set_skill("move",60);
    set_skill("parry",60);
    set_skill("force",60);
    set_skill("fireforce",60);
    set_skill("whip",60);
    set_skill("sunwhip",60);
    map_skill("force", "fireforce");
    map_skill("whip", "sunwhip");
    map_skill("force", "fireforce");
    setup();
    carry_object("/open/poison/obj/snake_whip")->wield();

}

int accept_kill(object ob)
{
	if( ob->query("kill_high2") )
        {
        write("少俠已經勝過在下,  恕在下不稍奉陪!!\n");
	return 0;
        }
	else
	{
        tell_object( ob ,"奉師尊之命與少俠切磋幾招!!\n");
        return 1;
	}
}

void die()
{
    object ob;
    ob= this_object()->query_temp("last_damage_from");
    if( ob && userp(ob) ) 
    {
    ob->add("combat_exp", 50000);
    ob->set("kill_high2", 1);
    write("少俠武學大進, 令人可敬!!\n");
    }
    ::die() ;
}


