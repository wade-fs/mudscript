//made by fund//change and organization by Urd 女神

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string to_kill();
string to_hurt();
string to_miss();
string to_miss2();
string to_miss3();
string to_miss4();
string to_miss5();
string ask_blade();

void create()
{
object ob;
set_name("葉秀殺",({"master yar","yar","master"}));
set("long","他是名震江湖的一代殺手﹐黑牙聯的頭目。\n");
set("gender","男性");
set("class","killer");
set("nickname","殺眼無情");
set("combat_exp",1500000);
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
set("quest/rain",1);
set_skill("rain-throwing",100);
set_skill("blade",20);
set_skill("cure",50);
set_skill("magic",20);
set_skill("literate",30);
set_skill("dodge",90);
set_skill("force",80);
set_skill("move",80);
set_skill("parry",60);
set_skill("dagger",90);
set_skill("shadow-kill",90);
set_skill("throwing",120);
set_skill("shade-steps",100);
set_skill("blackforce",95);
map_skill("throwing","rain-throwing");
map_skill("dodge","shade-steps");
map_skill("force","blackforce");
set("bellicosity",1500);
set_temp("apply/armor",70);
set("inquiry",([
"追殺令" : (: to_kill :),
"魔氣殺之傷" : (: to_hurt :),
"任務" : (: to_miss :),
"忍者" : (: to_miss2 :),
"追殺" : (: to_miss4 :),
"人頭" : (: to_miss5 :),
"黑血神針" : (: to_miss3 :),
"幽靈魔刀" : (: ask_blade :),
]));
set("force_factor",10);
set("chat_chance_combat",40);
set("chat_msg_combat",({
(:perform_action,"throwing.manakee":),
}));
setup();
create_family("黑牙聯",2,"主席");
ob=carry_object("/open/killer/obj/hate_knife");
ob->set_amount(200);
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
	if( this_player()->query("quests/to-kill") ) 
	{
	command("?");
	return "$N想幫我殺誰啊......";
	}
	if( present("letter",this_player() ) )
	{
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
 tell_object(me,HIY + "你中的不是魔氣殺，而是天魔解體大法的陰性氣指，目前只有莊靜柔
會使用。\n");
 tell_object(me,"因此，我想天魔解體大法被她拿走了吧\n");
 tell_object(me,"唉。。。看來她還是找上門來了，這是六年前的事情了。。。\n");
 tell_object(me,"當年柴榮受了說法大長老之託，假裝背叛而忍痛離開了莊靜柔\n");
 tell_object(me,"並且為了避免莊靜柔因恨而走火入魔，而將天魔解體大法取走\n");
 tell_object(me,"並且來到了黑牙聯，在前代主席葉孤城的指導下創出了霸雨式\n");
 tell_object(me,"當時，師父他原本要將主席之位傳給柴榮，但是因為莊靜柔的緣故\n");
 tell_object(me,"為了殺手的安全，師父他便將主席之位傳給了我，而與柴榮聯袂離開，
鑽研更上層的武學\n");
 tell_object(me,"但是柴榮他心中一直掛念著靜柔，而拜託了當時的兵器使完顏宏烈\n");
 tell_object(me,"將天魔解體大法，交給莊靜柔並且解釋清楚\n");
 tell_object(me,"豈知，完顏宏烈心生貪念，將天魔解體大法獨吞，並且連殺了好幾位魔
教徒\n");
 tell_object(me,"嫁禍給柴榮，而引起了莊靜柔的全面追殺令，逼使柴榮只好宣佈脫離黑
牙聯\n");
 tell_object(me,"以免引起黑牙聯與冥蠱魔教的全面對決，才使事件平靜了下來\n");
 tell_object(me,"但是，靜柔她並不原諒柴榮，因為她的心已死\n");
tell_object(me,"或許\你將他們的定情信物-滅神匕首。交給靜柔她，也許\她會想起當時
的甜蜜\n");
 tell_object(me,"滅神匕首在三樓的北邊房間，我派了一個屍魂人守住，殺了他就可以得
到\n" + NOR);
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
 tell_object(me,"你想知道哪一個任務？\n");
 tell_object(me,"目前有(忍者),(黑血神針)，（追殺），(人頭)四個任務\n");
 return "你想出任務嗎？";
}
string to_miss2()
{
  object ob,me;
 
 me=this_player();
 if (me->query("quest/rain") != 1)
   return "$N連魔氣殺都不會，還要出任務？";
 tell_object(me,"據說，紅葉組有東瀛伊賀派的忍者潛入，只有獨自一人\n");
 tell_object(me,"你去把他殺了，裝備在三樓，自己去拿\n");
  me->set_temp("mission1",1);
 return "人頭自己拿去換錢";
}
string to_miss3()
{
  object ob,me;
 
 me=this_player();
 if (me->query("quest/rain") != 1)
   return "$N連魔氣殺都不會，還要出任務？";
 tell_object(me,"那是一個沒有人知道的秘密，也就是黑血神針的所在地\n");
 tell_object(me,"那是當年楊小邪擊敗血變後，被潛入的黑巾殺手，由寒玲手中所偷走的
\n");
 tell_object(me,"目前似乎有人，拿著黑血神針到處傷人，你去把黑血神針追回來吧\n");
  me->set_temp("mission2",1);
 return "黑血神針可以找婆婆問它的下落";
}

string to_miss4()
{
  object ob,me;
 
 me=this_player();
 if (me->query("quest/rain") != 1)
   return "$N連魔氣殺都不會，還要出任務？";
  if(present("black blood",me))
 {
   tell_object(me,"你也拿到神針了呀！你知道神針的厲害了吧？\n");
   tell_object(me,"目前，那位拿著黑血神針到處傷人的人，似乎已經被黃龍祖組長發現
了\n");
   me->set_temp("mission3",1);
   return "$N可以去找他問看看(追殺者)";
 }
 return "$N你到底知不知道為何要追殺呀！先證明你知道神針之謎吧！";
}

string to_miss5()
{
  object ob,me;
 
 me=this_player();
 if (me->query("quest/memory") != 1)
   return "$N連殺手密令都沒有，還要出這一個重大任務？";
 tell_object(me,"近來，許\多人逐漸騎到殺手的頭上來了，看來其他門派羽翼已成\n");
 tell_object(me,"看來是藍鳳組出動的時間了，但是我也不能直接驅使藍鳳組\n");
 tell_object(me,"你幫我去執行任務吧！在花園那裡有藍鳳組的聯絡人\n");
 tell_object(me,"記住下列口訣，那是通過花園迷陣的方法\n");
 tell_object(me,"樹木逢三減一，石頭十丈反左。\n");
 tell_object(me,"花園迷陣景色會很相近，有如通吃小築那裡的迷陣\n");
 tell_object(me,"但是性質不同，你要相信你自己，勇敢的按照口訣所說，一定可以通過迷陣\n");
  me->set_temp("head",1);
 return "利用藍鳳組去將殺手全力追殺的人頭拿回來給我";
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
this_object()->set("bellicosity",1800);
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
HIB + "紛亂動蕩的武林中～～\n\n又出現一名恐怖的殺手～～\n" + NOR,users());
return 1;
}

int accept_object( object me , object ob )
{
object obj;
if(!ob->query("killer_wanted"))
{
	command("say 甚麼東西啊?");
	return 0;
}
if( me->query("quest/head-kill") == 1) return 0;
if( me->query_temp("head") != 10)  
	return notify_fail("看來你的任務有人幫過你，你還是請沒資格晉升\n");
command("nod");
command("chat* spank "+me->query("id"));
command("say 好小子，居然讓你完成這項任務，就讓我賜你當代殺手之名吧！！");
me->set("title",HIR + "當"+HIG"代"+HIY"殺"+HIB"手" + NOR);
me->set("quest/head-kill",1);
command("say 老夫為了獎勵你，就傳你殺意魔氣吧！");
message_vision("$N由掌心竄出一道紫氣射入$n體內。\n",this_object(),this_player());
me->set("sec_kee","mkill");
command("say 你已經資格知道到藍鳳組所在地，就是在地下水道二層，但目前仍沒有獲喬小雨同意。");
command("say 等小渡一段時間，他把藍鳳組機關做好，或許\喬小雨就會同意你去吧！");
message("system",
HIM + "葉秀殺大笑：『哈哈。。。江山代有才人出！一代新人換舊人\n\n"+me->query("name")
    +"你就代替老夫在武林裡面，將與黑牙聯作對的人一一消滅吧！』\n" + NOR,users());
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

void unconcious()
{
       object hu_fa;
        object winner = query_temp("last_damage_from");
       
       message("system",HIM + "想不到我葉秀殺，居然會敗在"+winner->query("name")+"
手中\n"+
                "看來"+winner->query("id")+"你是皮在癢了！！！！\n",users());
       message("system"
                ,HIR + "可惡！！紅葉組，銀狼組！把"+winner->query("name")+"人頭提來
見我！\n" + NOR,users());

       hu_fa = new("/open/killer/npc/silnpc2.c");
       hu_fa->move(environment(winner));
       hu_fa->command("guard behavior_elder");
       hu_fa->command("follow "+winner->query("id"));
       hu_fa->kill_ob(winner);
       hu_fa = new("/open/killer/npc/rednpc2.c");
       hu_fa->move(environment(winner));
       hu_fa->command("guard behavior_elder");
       hu_fa->command("follow "+winner->query("id"));
       hu_fa->kill_ob(winner);
       new("/open/killer/npc/spy3")->move("/open/killer/room/masterm.c");
        :: unconcious();
}

void die()
{
 string head;
        object winner = query_temp("last_damage_from");
       if (winner->query("class") != "killer")
       {
         message("system",HIR + "超級殺手柴容放聲大叫，\n各位殺手聽著，"+winner->query("name")+
                "把葉秀殺給掛了\n各位殺手給我全力追殺，"+winner->query("id")+"！！\n" + NOR,users());
		/*	這樣設會有問題..修正 by chan
			winner->set("title",HIR + "殺手全力追殺的人頭" + NOR);
		*/
        head=winner->query("title");
        winner->set("KILLTITLE",head); //暫存.等回來,回來在damage.c中
	winner->set("title",HIR + "殺手全力追殺的人頭" + NOR);
        }
        :: die();
}


