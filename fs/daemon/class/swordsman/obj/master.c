#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
int ask_gonfu();
int sha_array3();
int sha_array4();
int sha_array8();
int check_mogi(object me)
{ 
 command("fear");
 message_vision(HIY"
$N驚恐的說：你這是中了魔域的劇毒「入滅」！因毒素潛藏奇經八脈之中
每隔一段時間會嘔血不止，時間一長甚至會送命，當今只有「菩薩印第十式」
能化解此招！\n"NOR,this_object());
}

int pass(object me)
{ 
 command("sigh");
 message_vision(HIY"$N面帶感傷，似乎想起了某件傷心往事...\n"NOR,this_object());
 message_vision(HIC"
$N緩緩的說：那是我年輕的時候的事了...當時仙劍祖師逍遙子尚未失蹤，魔域突
然大舉進犯人間，於是各門派便聯手與魔兵奮戰......
當時老夫年少輕狂，剛剛練成了仙劍至極之招---雙十旋龍斬！
臨陣對敵時，老夫為逞一時之勇，也想藉此機會展現此招的威力，於是顧不得此招尚
未完全熟練便使出了「雙十旋龍斬」，但卻誤傷了少林的空性大師。而我也因此中門
大開被魔將以「入滅」暗中偷襲，從此以後每過十二個時辰老夫便嘔血一次，命在垂
危。而空性大師得知此事，先以渾厚內力將自己的傷勢強行鎮壓，再把自己的「菩薩
印第九式」推進到第十式為老夫療傷，但自己卻在三天後舊傷復發加上菩薩印威力無
法承受而圓寂了。故老夫發誓此生不再用雙十旋龍斬。
至於你的傷是否能得救，趕快前去少林寺會見住持看看是否有辦法。\n
"NOR,this_object());

}
string check_damage()
{
	object me = this_player();
	if( me->query("quests/kill-dugur") && !me->query("quests/cure-star") )
	return "你中的是雪蒼派的絕招「枯\葉殘星掌」﹐這一掌勁道十分強﹐可見此人非汎汎之輩。\n";
	return "你有受傷嗎 ?";
}
string cure_damage()
{
	object me = this_player();
	if( me->query("quests/kill-dugur") && !me->query("quests/cure-star") )
	return "對於這個傷﹐我並沒有把握﹐但是﹐據我所知﹐魔刀有研究過這部功\夫。\n";
	return "你有受傷嗎 ?";
}
void create()
{
set_name("鄭士欣",({"master teng","teng","master"}));
set("long","他就是武林第一大宗師 :鄭士欣。現正執掌仙劍門戶，
同時身為劍士公會總會長。近十餘年來，因仙劍七俠已
能獨當一面，分擔派內事務；而公會事務也由三長老柳
毅全權負責，鄭士欣每天除了至藏經閣精研武學外，就
是在此接見外賓。\n");
	set("gender","男性");
	set("class","swordsman");
	set("nickname","無極真人");
            set("family/family_name","仙劍派");
            set("combat_exp",1400000);
            set("attitude","heroism");
            set("dragon-sword",1);
            set("bellicosity", 490);
	set("age",76);
	set("title","仙劍派第三代掌門人");
            set("str", 44);
            set("cor", 42);
	set("cps", 18);
	set("con", 24);
	set("int", 42);
            set("max_gin", 4000);
            set("gin",4000);
            set("max_kee", 5900);
            set("kee",5900);
            set("s_kee",1000);
            set("max_s_kee",1000);
            set("sec_kee","god");
	set("force",4400);
            set("max_force",4400);
            set("functions/sha_kee/level",100);
	set_skill("literate",40);
            set_skill("cure",50);
            set_skill("magic",20);
            set_skill("spells",20);
            set_skill("shasword",100);
	set_skill("shaforce",80);
            set_skill("sha-steps",100);
            set_skill("sha-array",100);	
	set_skill("array",100);
	set_skill("move",80);
	set_skill("force",50);
	set_skill("dodge",80);
	set_skill("parry",120);
	set_skill("sword",120);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        map_skill("parry","shasword");
	set("force_factor",29);
	set("inquiry",([
  "仙劍後三式" : (: ask_gonfu :),
  "三才密招" : (: sha_array3 :),
  "四龍崩月" : (: sha_array4 :),
  "禁斷連斬訣" : (: sha_array8 :),
  "鎖元盒" : "這樣東西似乎在二十年前左右就失落了﹐而它最後出現的地方好像是在雪蒼山上。\n",
  "我的傷" : (: check_damage :),
  "療傷" : (: cure_damage :),
  "仙劍劍陣" : "劍陣因人數不同有其不同陣招，「三才密招」「四龍崩月」「禁斷連斬訣」等招 !!",
  "枯葉殘星掌" : "這招是雪蒼派的禁招之一﹐威力十分驚人﹐但是﹐這部功\夫似乎在獨孤愁死後就已經失傳了。\n",
  "入滅" : "我年輕時對抗魔域入侵時曾中過此毒，九死一生幸得一位「高僧」施展菩薩印第十式為我解之，但是，唉...",
  "菩薩印第十式" : "此為少林佛門菩薩十式中的最高禁招，第十式威力實在太強，所以修練者若功力不足，會在
數日內反傷己身而死，故歷代高僧非必要不會將\功\力\推進到第十式。",
  "高僧" :  (: pass :),
	]));
	set("get_sha_sp", 1);
            set("bounds", 4000000);
	set("chat_chance_combat",90);
	
	set("chat_msg_combat",({
        (: perform_action,"sword.sha_kee" :)
	}));
	setup();
	carry_object("/open/gsword/obj/dragon-sword.c")->wield();
		add_money("gold",10);
	create_family("仙劍派",3,"掌門人");
}

void init()
{
  object me = this_player();
  if(me->query_condition("mogi"))
  call_out("check_mogi",1,me);

        add_action("do_select","select");
        add_action("do_verify","verify");
}

int accept_fight(object who)
{

object guard, guard1;
 command("cmd god_kee");
 fight_ob(who);
 command("perform sword.sha_kee");
 return 1;
}

int accept_kill(object who)
{
 object guard, guard1;

 command("say 讓你知道連陽劍的厲害！\n");
 set("have_kill_me",1);
 kill_ob(who);
 command("cmd god_kee");
 command("perform sword.sha_kee");
command("say 隨風 ,語柔出來替老夫收拾這小伙子 !!");
     if(!present("dragon cloth")){ 
carry_object("/open/gsword/obj/dragon-cloth.c")->wear();

        guard=new("/daemon/class/swordsman/boy.c");
        guard->move( environment() );
        guard1=new("/daemon/class/swordsman/girl.c");
        guard1->move( environment() );
}
        guard1->kill_ob(who);
        guard->kill_ob(who);

 return 1;
}


int do_verify(string arg)
{
 object me,ob;
 me=this_player();
 ob=new("open/gsword/obj/b1");
 if( arg!="sword")
{
    write("你要申請什麼\n");
    return 1;
   }
if(me->query("family/family_name")!="仙劍派")
  {
    write("只有仙劍門徒才會有信物\n");
    return 1;
  }

 if( present(ob,me) )
  {
    write("你已經申請過了\n");
    return 1;
   }
   else
    {
     write("鄭士欣說：這是仙劍派的信物 ,望你好好保存 ,切勿遺失了\n");
     ob->move(me);
     return 1;
    }
}

void attempt_apprentice(object ob)
{
	if(ob->query("marks/仙劍七俠")==1)
	{
	if((int)this_player()->query("combat_exp")<=100000)
	{
	command("? " +ob ->query("id"));
	command("say 你不是拜過我的弟子了?");
	command("say 以你的程度還不須我親自指導!");
	command("say 好好跟著你師父多學幾年吧!");
	return 0;
	}
	command("look "+ob->query("id"));
	command("smile");
	command("say 好,你果然是可造之才,從今後就由老夫親自指導!");
	// Modify By Oda
	// 為了避免叛師被扣 skill, 先將玩家的 family 去掉
	ob->delete("family");
	command("recruit "+this_player()->query("id"));
	message("system",HIW"鄭士欣縱聲大笑: 
哈哈哈哈....老夫實在太高興啦!
英雄出少年 ,"+this_player()->name()+": 今後就由老夫親授於你.\n"NOR,users());
	return ;
	}
      command("hmm");
      command("say 我老啦 ,你去拜我的七個徒弟吧 !");
      command("say 我的七個弟子是 張乘風 張乘雲 唐鈺 趙鶴 梅影 何雙雙 李逍遙");
      command("say 你想拜(select)誰呢?");
      ob->set_temp("allow_select",1);
}

	int do_select(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又沒答應讓你挑? ");
	return 1;
	}
	if(who->query_temp("have_say")==1)
	{
	message_vision(sprintf(HIC"$N說道﹕"+str+"\n"NOR),who);
	command("say 你不是挑過了?");
	return 1;
	}
	if(str=="張乘風" ||  str == "chen fon" || str == "fon")
            {
	 message_vision(HIC"$N說道﹕張乘風\n"NOR,who);
 	 this_player()->set_temp("allow_1",1);
	 command("smile");
	 command("say 嗯 ,你就拜我的首徒張乘風吧!");
	 this_player()->set_temp("have_say",1);
	 return 1;
	}
	if(str == "張乘雲" || str == "chen un" || str == "un")
	{
	message_vision(HIC"$N說道﹕張乘雲\n"NOR,who);
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就拜我的次徒張乘雲吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "唐鈺" || str == "teng yu" || str == "yu")
	{
	message_vision(HIC"$N說道﹕唐鈺\n"NOR,who);
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就拜我的三弟子唐鈺吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "趙鶴" || str == "san hu" || str == "hu")
	{
	message_vision(HIC"$N說道﹕趙鶴\n"NOR,who);
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就拜我的四弟子趙鶴吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "梅影" || str == "may ying" || str == "may")
	{
	message_vision(HIC"$N說道﹕梅影\n"NOR,who);
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子梅影吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "何雙雙" || str == "cute girl" || str == "girl")
	{
	message_vision(HIC"$N說道﹕何雙雙\n",who);
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子何雙雙吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "李逍遙" || str == "shou_yau" || str == "yau")
	{
	message_vision(HIC"$N說道﹕李逍遙\n"NOR,who);
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就拜我的七弟子李逍遙吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	command("say 沒這人!");
	return 1;
	}
  
int  ask_gonfu()
{
  object me;
  me=this_player();
  if( me->query_skill("shasword",1) < 80 )
 write(" 你武\功\需要再加強些 ,不要胡思亂想\n ");
 else if(me->query("bounds",1) < 4000 )
 write("你對本派貢獻還不足 ,等夠了我再告訴你吧\n");
 else 
    {
     write("好像有這\功\夫 ,不過百年前已經失傳 ,這樣好了 ,你去藏經閣找找吧\n");
     new("/open/gsword/obj/pass")->move(me);
     write("這張通行証你拿去給乘雲看 ,他就會讓你進去的. \n");
     me->set_temp("allow_pass",1);
    }     	
     return 1;
}
	
int  sha_array3()
{
  object me;
  me=this_player();
  if( me->query("family/family_name") !="仙劍派")
  command("say 你非仙劍弟子，恕不奉告");
  else command("say 其實這是我憑空想出來的，如果有一天有三個人同時會使用仙劍後三式
的話，試試此招也\許\可以融成絕招也說不定，前提是三人的劍陣修為必須要夠。");
  return 1;
}	
int  sha_array4()
{
  object me;
  me=this_player();
  if( me->query("family/family_name") !="仙劍派" )
  command("say 你非仙劍弟子，恕不奉告");
  else command("say 老夫因某種原因不使用雙十旋龍斬，但我仍然想過將四人雙
十同時施展如何合一的方法，但我自己也沒試驗過。");
  return 1;
}
int  sha_array8()
{
  object me;
  me=this_player();
  if( me->query("family/family_name") !="仙劍派" )
  command("say 你非仙劍弟子，恕不奉告");
  else command("say 此招融合仙劍七俠的禁斷絕招和老夫的劍訣，但我的弟子的平均
\功\力\不夠，所以此招列為仙劍的禁招之一。");
  return 1;
}
void unconcious()
{
   object winner = query_temp("last_damage_from");
   tell_object(users(),HIW"鄭士欣吟道：\n\n\n            "HIW"『"HIC"狂歌羨煞紅塵客      笑歎人間\幾\許\愁 \n
              曉霧迷濛秋漸冷      只恨雲深願未酬"HIW"』\n\n\n"HIW"今日敗於"HIY+winner->query("name")+HIW"少俠之手，老夫心悅誠服，盼少俠能以一身絕學振興武林!!\n"NOR);
   :: unconcious();
}
void die()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),HIM"\n\n只見蜀山上朵朵"HIY"彩雲"HIM"冉冉升起，剎為奇觀\n\n\n"HIW"    一代劍術宗師「"HIC"鄭士欣"HIW"」嗑然長逝了...\n\n"NOR);

        :: die();
}     		
