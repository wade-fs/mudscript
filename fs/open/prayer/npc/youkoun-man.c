//燕十一
#include <command.h>
 
inherit NPC;

string ask_red()
{
    object who=this_player();
    if( who->query_temp("youkoun") >= 4 )
    {
    who->set_temp("red",1);
    return("她現在在那裡我也不知道, 不過我在你身上已經做了記號, 只要她一見到就會發現了!!\n");
    }
    else
    {
    return("相信你已經從周琇虔那裡聽到不少東西了吧!!\n");
    }
}

string ask_whip()
{
    object who=this_player();
    if( who->query_temp("kill_youkoun") && who->query_temp("help_red") && !who->query("quests/sunwhip"))
    {
    who->set("quests/sunwhip",1);
    who->set_skill("sunwhip",5);
    who->add("max_force",50);
    return("你幫了我就等於是幫了霞山派了!!這落日鞭法就傳了你吧!!\n");
    }
    else
    {
    return("落日鞭法是不能夠隨便就傳授他人的!!您還是不要打它的主意吧!!\n");
    }
}

void create()
{
    set_name("燕十一",({"man-eleven","man","eleven"}));
    set("title", "霞山");
    set("gender", "男性");
    set("age",32);
    set("attitude","friendly");
    set("long",@LONG

	霞山派弟子--燕十一, 因故被囚於此, 全身傷痕累累
	不過眼神中仍是透出一股精壯之光.........

LONG);
 
    set("combat_exp",432000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",500);
    set("kee",500);
    set("max_force",500);
    set("force_factor", 25);
    set("force",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",150);
    set_skill("move",150);
    set_skill("parry",150);
    set_skill("whip",120);
    set_skill("sunwhip",120);
    set_skill("force",120);
    set_skill("fireforce",120);
    map_skill("force", "fireforce");
    map_skill("whip", "sunwhip");
    map_skill("parry", "sunwhip");
    set("inquiry",([
    "霞山派":"霞山派的武學路數, 係師祖所創之[落日鞭法]!\n",
    "秘笈":"秘笈藏在紅姑那裡!!不過我被困於此沒人知道!!\n",
    "落日鞭法":(: ask_whip :),
    "紅姑":(: ask_red :),
 ]));
    setup();
    carry_object("/open/prayer/obj/ligature")->wield();
}

void greeting(object who)
{
    if( who->query_temp("kill_red") >= 2 ) 
    {
    write("    你竟然殺了我師姐, 還想要我派鞭法的密笈!!哼!!霞山派從此與
    你永無寧日!!我現在就先跟你拼了!!\n");
    kill_ob(who);
    return;
    }
}

void die()
{

    object who;
    who= this_object()->query_temp("last_damage_from");
    if( who && userp(who) ) 
    {
    who->set("kill_eleven", 1);
    write("\n謝謝你殺了我, 我在下面可以快樂地跟師姐在一起了!!\n");
    }
    ::die() ;
}
