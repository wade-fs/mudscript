//男塾三面拳,為ctitle npc  -CHAD-20090420

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
    object ob;
    set_name("月光",({"yua-guang"}));
    set("long","
男塾三面拳之一，十分冷酷，標準的撲克臉。絕招為纏頦針點\n");
    set("gender","男性");
    set("class","fighter");
    set("combat_exp",30000000);
    set("attitude","heroism");
    set("title","" + HIW + "男塾三面拳" + NOR + "");
    set("nickname",HIY + "強" + NOR);
    set("no_fight",1);
    set("no_kill",1);
    set("no_plan",1);
    set("age", 25);
    set("str", 30);
    set("cor", 30);
    set("cps", 30);
    set("per", 30);
    set("int", 30);
    set("kar", 30);
    set("score",9000000);
    set("kee",10000000);
    set("max_kee",10000000);
    set("gin",10000000);
    set("max_gin",10000000);
    set("sen",10000000);
    set("max_sen",10000000);
    set("atman",10000000);
    set("max_atman",10000000);
    set("mana",10000000);
    set("max_mana",10000000);
    set("force",10000000);
    set("max_force",10000000);
    set("quest/rain",1);
    set("adv_dancer",1);
    set_skill("move",100);
    set_skill("parry",100);
    set_skill("dodge",100);
    set_temp("apply/armor",700);
    set("force_factor",10);
    set("inquiry",([
	"三面拳":"男塾三面拳為我,飛燕及雷電.",
	"信物":"你非男塾三面拳之一,憑什麼跟我拿信物?",
	"大豪院邪鬼":"他是我們男塾永遠的三號生筆頭!是男塾永遠尊敬的學長!",
	"江田島平八":"男塾塾長-江田島平八!!",
	"劍桃太郎":"桃太郎啊...謎樣的人物呢,一號生筆頭非他莫屬!",
      ]));
    setup();
}

void init()
{
    ::init();
    add_action("do_reveal","reveal");
}

void greeting()
{
    object ppl = this_player();
    object obj = this_object();

    if(!ppl->query("quests/ctitle")){
	ppl->set_temp("findyua",1);
	command("hmm");
	return ;}
    command("spank "+ppl->query("id"));
}

int do_reveal(string str)
{
    object ppl = this_player();
    object obj = this_object();
    object obj2;

    if(!str){return notify_fail("你想秀什麼?\n");}
    obj2 = present(str,ppl);
    if(!obj2){return notify_fail("...你身上沒這樣東西,想展示什麼?\n");}
    if((obj2->query("id")=="lay-mark")||(obj2->query("id")=="fay-mark")){
	write("你從身上拿出"+obj2->query("name")+"給"+obj->query("name")+"看，只見"+obj->query("name")+"看的入神.\n");
	ppl->set_temp("show-to-yua",1);
	call_out("msg1",0,ppl);
	return 1;}return notify_fail("你從身上拿出"+obj2->query("name")+"給"+obj->query("name")+"看,只不過"+obj->query("name")+"一點反應也沒有.\n");
}

int msg1()
{
    object ppl = this_player();
    object obj = this_object();
    object obj2;

    if(ppl->query_temp("show-to-yua")==1&&!ppl->query_temp("yua-ok")){
	command("hmm");
	command("say 看來你曾經見到仍在世上的三面拳,他們人好嗎?");
	command("say 既然你有幸遇見他們,就麻煩你下次若在見到他們，將這個信物給他們看,他們看了即知!");
	obj2=new("/open/ctitle/obj/yua-mark.c");
	obj2->move(ppl);
	write("" + HIY + ""+obj->query("name")+"將"+obj2->query("name")+"" + HIY + "交給了"+ppl->query("name")+"" + NOR + "\n");
	log_file("open-area/ctitle/yuamark", sprintf("%s(%s) 從月光這裏拿走%s in %s\n",ppl->query("name"),ppl->query("id"),obj2->query("name"), ctime(time()) ));
	ppl->set_temp("yua-ok",1);
	return 1;}
    if(ppl->query_temp("yua-ok")==1){
	command("say 就有勞你替我打聽其餘三面拳的下落了!");return 1;}
}
