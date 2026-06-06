
#include <command.h>
 
inherit NPC;
string ask_kylin()
{
    object who=this_player();
    if(who->query("marks/聖火八天門",1) && who->query_temp("can_pass"))
    {
    return("第..二..根..渾..天..水..晶..就..放..在..囹..圄..池..的..池..中..\n");
    who->set_temp("ask_hurted",1);
    }
    else
    {
    return(" 對..不..起..我..不..能..夠..告..訴..你... \n");
    }
}

void create()
{
    set_name("傷者",({"hurter"}));
    set("title", "洞窟內的");
    set("gender", "男性");
    set("age",46);
    set("attitude","friendly");
    set("long",@LONG
	躺在地上的這位傷者, 受傷非常的嚴重而且已經奄奄一息, 雖然
	你想要救他, 可是卻不知道有沒有這個能力..從他身上的衣服來
	看, 他應該是聖火教的門生吧! 身上掌印處處, 絕對是怪獸所留
	下來的...........
LONG);
 
    set("combat_exp",32000);
    set("str",16);
    set("con",14);
    set("int",12);
    set("max_kee",50);
    set("kee",50);
    set("max_force",500);
    set("force",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set("chat_chance",30);
    set("chat_msg", ({
    "微弱的呻吟聲:...救.....救......我.......!!\n",
    "......我.......我........我..........!!\n", 
    }) );
    set("inquiry",([
    "我":"我是天機門的拳師, 因為門主要我.來這.裡.拿一.樣..東...西\n",
    "東西":"是...渾...天...水...晶..就...放..在...\n",
    "哪裡":"在........血.......麒.........麟.........的...........\n",
    "血麒麟":(: ask_kylin :),
 ]));
    setup();
}

int accept_fight(object who)
{
    return notify_fail("只聽到傷者無力地呻吟著...........................");
}
