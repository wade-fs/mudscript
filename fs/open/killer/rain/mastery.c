//made by fund//change and organization by Urd 女神

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string to_kill();
string to_hurt();
string to_miss();
string ask_blade();

void create()
{
object ob;
set_name("葉秀殺",({"master yar","yar","master"}));
set("long","他是名震江湖的一代殺手﹐黑牙聯的頭目。\n");
set("gender","男性");
set("class","killer");
set("nickname","殺眼無情");
set("combat_exp",1000000);
set("attitude","heroism");
set("age",26);
set("str", 44);
set("cor", 34);
set("cps", 18);
set("per", 24);
set("int", 42);
set("kee",3000);
set("max_kee",3000);
set("gin",1600);
set("max_gin",1600);
set("atman",1200);
set("max_atman",1200);
set("mana",1000);
set("max_mana",1000);
set("force",3500);
set("max_force",3500);
set_skill("rain-throwing",100);
set_skill("blade",50);
set_skill("cure",50);
set_skill("literate",40);
set_skill("dodge",90);
set_skill("force",80);
set_skill("move",100);
set_skill("parry",80);
set_skill("dagger",90);
set_skill("poison",60);
set_skill("sword",50);
set_skill("throwing",100);
set_skill("shade-steps",100);
set_skill("blackforce",95);
map_skill("throwing","rain-throwing");
map_skill("dodge","shade-steps");
map_skill("force","blackforce");
set("force_factor",10);
set_temp("apply/armor",70);
set("inquiry",([
"追殺令" : (: to_kill :),
"魔氣殺之傷" : (: to_hurt :),
"任務" : (: to_miss :),
"幽靈魔刀" : (: ask_blade :),
]));
set("force_factor",10);
set("chat_chance_combat",40);
set("chat_msg_combat",({
(:perform_action,"throwing.rain":)
}));
setup();
create_family("黑牙聯",2,"主席");
ob=carry_object("/open/killer/obj/hate_knife");
ob->set_amount(100);
ob->wield();
carry_object("/open/killer/weapon/k_cloth3.c")->wear();
carry_object("/open/killer/weapon/k_boot3.c")->wear();
carry_object("/open/killer/weapon/k_arm3.c")->wear();
carry_object("/open/killer/weapon/k_head3.c")->wear();
}
void init()
{
add_action("do_join","join");
}
string to_kill()
{
object ob;
if( this_player()->query("quests/to-kill") ) {
command("?");
return "$N想幫我殺誰啊......";
}
if( present("letter",this_player() ) ){
command("?");
return "$N已經拿到密函了...不是嗎??";
}
command("look "+this_player()->query("id"));
command("hmm");
ob = new(__DIR__"letter");
ob->move( this_player() );
message_vision("$N遞給$n一封密函。\n",this_object(),this_player());
return "這裡面寫著被追殺的人........";
}

string to_hurt()
{
 object ob;
 object me;

 me=this_player();
 if( me->query_temp("hurt") !=1 )
 {
   command("?");
   return "$N在說什麼呀？";
 }
 tell_object(me,HIY"唉。。。看來她還是找上門來了，這是六年前的事情\n");
 tell_object(me,"當年柴榮受了說法大長老之託，假裝背叛而忍痛離開了莊靜柔\n");
 tell_object(me,"並且為了避免莊靜柔因恨而走火入魔，而將天魔解體大法取走\n");
 tell_object(me,"並且來到了黑牙聯，在前代主席葉孤城的指導下創出了霸雨式\n");
 tell_object(me,"當時，師父他原本要將主席之位傳給柴榮，但是因為莊靜柔的緣故\n");
 tell_object(me,"為了殺手的安全，師父他便將主席之位傳給了我，而與柴榮聯袂離開，鑽研更上層的武學\n");
 tell_object(me,"但是柴榮他心中一直掛念著靜柔，而拜託了當時的兵器使完顏宏烈\n");
 tell_object(me,"將天魔解體大法，交給莊靜柔並且解釋清楚\n");
 tell_object(me,"豈知，完顏宏烈心生貪念，將天魔解體大法獨吞，並且連殺了好幾位魔教徒\n");
 tell_object(me,"嫁禍給柴榮，而引起了莊靜柔的全面追殺令，逼使柴榮只好宣佈脫離黑牙聯\n");
 tell_object(me,"以免引起黑牙聯與冥蠱魔教的全面對決，才使事件平靜了下來\n");
 tell_object(me,"但是，靜柔她並不原諒柴榮，因為她的心已死\n");
 tell_object(me,"或許你將他們的定情信物-滅神匕首。交給靜柔她，也許她會想起當時的甜蜜\n");
 tell_object(me,"你中的不是魔氣殺，而是天魔解體大法的陰性氣指，目前只有靜柔她會。\n");
 tell_object(me,"因此，我想天魔解體大法被她拿走了吧\n");
 tell_object(me,"滅神匕首在三樓的北邊房間，我派了一個屍魂人守住，殺了他就可以得到\n"NOR);
 me->set_temp("god",1);
 return "$N在三樓調查一下，可以找到進去的開關";
}
string to_miss()
{
 object ob;
 object me;

 me=this_player();
 if( me->query("quest/rain") !=1 )
 {
   command("sm");
   return "$N連魔氣殺都還不會，還想出什麼任務？";
 }
 tell_object(me,"據說，紅葉組有東瀛伊賀派的忍者潛入，只有獨自一人\n");
 tell_object(me,"你去把他殺了，裝備在三樓，自己去拿\n");
  me->set_temp("mission1",1);
 return "人頭自己拿去換錢";
}

void attempt_apprentice(object ob)
{
command("l "+ob->query("id"));
if(this_player()->query_cor()<20)
{
command("sigh "+ob->query("id"));
command("say 你的膽識不夠, 我不能收。\n");
return;
}
command("smile");
command("nod");
command("say 好！！");
command("recruit "+ob->query("id"));
}
int accept_fight(object ob)
{
command("say 真有骨氣！！好, 我接受挑戰！！");
message_vision( this_object()->name()+"臉上露出高興的樣子。\n",ob);
this_object()->set("bellicosity",1000);
command("cmd bellup");
return 1;
}
int accept_kill(object ob)
{
command("say 沒想到居然有人敢來這撒野！！");
message_vision( this_object()->name()+"突然變臉﹐臉上出現殺氣。\n",ob);
this_object()->set("bellicosity",3000);
command("cmd bellup");
return 1;
}
int do_join()
{
object ob=this_player();
if(!ob->query("class"))
{
ob->set("class","killer");
command("nod "+ob->query("id"));
}
else
{
command("say 志不同道不合, 另找明師去吧。\n");
return 1;
}
message("system",
HIB "紛亂動蕩的武林中～～\n\n又出現一名恐怖的殺手～～\n" NOR,users());
return 1;
}
int accept_object( object me , object ob )
{
object obj;
if( !ob->query("true-corpse") )
{
command("say 甚麼東西啊?");
return 0;
}
if( me->query("quests/to-kill") ) return 0;
command("nod");
obj = new("/open/snow/obj/ghost-blade");
obj->move(this_player());
message_vision("$N給$n一把"+obj->name()+"。\n",this_object(),
this_player());
me->set("quests/to-kill",1);
}
string ask_blade()
{
object ob;
if( present("ghost blade",this_player()) ) return "想要甚麼 ?";
if( !this_player()->query("quests/to-kill") ) return "想要甚麼 ?";
ob = new("/open/snow/obj/ghost-blade");
ob->move(this_player());
message_vision("$N給$n一把幽靈魔刀。\n",this_object(),this_player());
return "不要再弄掉了...";
}
