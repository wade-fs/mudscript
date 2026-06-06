// master_jen.c
// Chan 22/5重新設計
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string test();
string kee_god();
string ask_yan();
string super_fighter();
void create()
  {
        set("class", "fighter");
        set_name("任正晴", ({ "master jen", "master", "jen" }) );
        set("title","瀧山派第七代掌門人");
        set("nickname", "瀧山奇俠");
        set("gender", "男性");
        set("age", 45);
        set("del_delay",1);
        set("attitude", "hero");
        set("long",
        "任正晴自幼生長於武學名門中﹐受其父「任博文」英才式的教育，薰\n"
        "陶出其嚴肅而謙遜的人格，身為瀧山派掌門的他，以發揚瀧山為己任\n"
        "，對於違反派規的弟子毫不留情，如此就可看出其嚴肅的個性\n");
        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);
        set("fire_strike",1);
        set("super_fire",1);
        set("combat_exp",5000000);
        set("max_kee",50000);
        set("kee",50000);
        set("max_gin",15000);
        set("gin",15000);
        set("max_sen",15000);
        set("sen",15000);
        set("force"       , 15000);
        set("max_force"   , 15000);
	set("atman"       , 15000);
        set("max_atman"   , 15000);
	set("mana"       , 15000);
        set("max_mana"   , 15000);
        set("force_factor", 40);
        set("score"       , 200000);
        set("s_kee",1000);
        set("env/瀧山連擊","YES");
        set("max_s_kee",1000);
        set("sec_kee","tiger");
        set("inquiry",([
                 "瀧山拳法":   "此為任家傳承的絕學，分為「素招」、「禁斷」、「奧義」三種。 ",
                 "素招":       "是瀧山拳法中較易學、威力較小的招式。\n",
                 "禁斷":       "瀧山禁斷共有「山水之氣」、「吼嘯山林」二招。\n"
                               "只有瀧山拳法至登峰造極之際才能接受考驗傳授\n",
                 "奧義":       "是上任掌門任溥文將瀧山拳結合浩日真氣所創出的絕招。\n"
                               "稱之為『赤焰神掌』共三式\n"
                               "只有瀧山絕學傳人且有特別貢獻才能傳授\n",
                 "禁斷考驗":   (: test :),
                 "風青雲" : (: ask_yan :),
                 "仙雲之氣":   (: kee_god :),
                 "玄天聖地":   (: super_fighter :),
                 "葉狂":       "三十年前橫行江湖無惡不做的大魔頭，被上代掌門囚禁在監牢中\n",
                 "監牢":       "在瀧山的禁地中\n",
          ]));
        set("functions/kang_kee/level",100);
        set_temp("roared", 1 );
		set_temp("kang-power", 1 );
        set_skill("cure",40);
        set_skill("move",50);
        set_skill("unarmed", 120);
        set_skill("force",120);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("fire-kee",100);
        set_skill("literate",40);
        set_skill("henma-steps",100);
	set_skill("literate",30);
        set_skill("lungshan",100);
	set_skill("haoforce",100);

        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
        }));
        create_family("瀧山派", 7, "掌門人");
        setup();
            carry_object(__DIR__"ywleg")->wear();
            carry_object(__DIR__"ywboots")->wear();
            carry_object(__DIR__"ywcloth")->wear();
            carry_object(__DIR__"ywgem")->wear();
            carry_object(__DIR__"ywhelme")->wear();
            carry_object(__DIR__"ywhand")->wear();
            carry_object(__DIR__"ywsu")->wear();
            carry_object(__DIR__"armband")->wear();
               carry_object(__DIR__"star");
                carry_object(__DIR__"figring")->wield();
        add_money("gold",40);
}

int accept_object(object who, object ob)
{
  object mid;
  if( ob->query("id") == "ya-head")
  {
    destruct(ob);
    say("任正晴仔細對葉狂的頭審視,說道:這竟然是『血魔』葉狂的頭。\n");
    who->set("quests/ya",1);
    if( who->query("family/family_name")=="瀧山派"&&who->query_skill("lungshan",1) < 70)
	{
	 say("任正晴怒道:瀧山派的武學都沒有學好了,還想學什麼禁技!!!\n");
	 return 0;
    }
    else if( who->query("family/family_name")=="瀧山派")
     {
	 
      if(!who->query("fire_strike",1))
       {
        say("你為武林除去這萬惡魔頭，立下如此大的功\勞!\n"
            "嗯!!好吧!!我便將瀧山的終極奧義『赤焰神掌』傳授給你\n");
        who->set("fire_strike",1);
        who->set("title","瀧山奧義傳人");
       }
      else
       {
        say("你為武林除去這萬惡魔頭，立下如此大的功\勞!!\n"
            "這些是我多年來收集的雪蓮丹及靈芝仙丹都給你吧\n");
        mid=new("/open/gsword/obj/ff_pill");
        mid->add_amount( who->query_per()+100 );
        mid->move(who);
        mid=new("/open/gsword/obj/f_pill");
        mid->add_amount( who->query_per()+100 );
        mid->move(who);
       }
     }
     else
     {
      if(!who->query("get_force",1))
       {
        say("你為武林除去這萬惡魔頭，立下如此大的功\勞!!\n"
            "嗯!!好吧!!我將部份內力傳授給你吧!!\n");
        message_vision(HIC + "任正晴將雙手按住$N檀中穴，真氣瞬時間打通$N的任督二脈\n",who);
        who->add("max_force",200);
        who->set("get_force",1);
       }
      else
       {
        say("你為武林除去這萬惡魔頭，立下如此大的功\勞!!\n"
            "這些是我多年來收集的雪蓮丹及靈芝仙丹都給你吧\n");
        mid=new("/open/gsword/obj/ff_pill");
        mid->add_amount( who->query_per()+100 );
        mid->move(who);
        mid=new("/open/gsword/obj/f_pill");
        mid->add_amount( who->query_per()+100 );
        mid->move(who);
       }
     }
} else
  if( ob->query("id") == "tiger-head")
  {
    destruct(ob);
    if((who->query("family/family_name") == "瀧山派") && (who->query("lungshan_test") != 1))
     {
      say("任正晴仔細的看了看!!,說:這不是獨角虎的頭!!。\n");
      return 0;
     }
    if((who->query("family/family_name") != "瀧山派") || who->query("super_fire"))
     {
      say("任正晴仔細的看了看!!,說道:果然是惡獸的頭!!感謝你為武林除此大害。\n");
      who->set("go_ya",1);
      return 0;
     }
    say("任正晴仔細的看了看!!說道:這果然是殘害無數百姓惡獸--獨角虎--的頭。\n");
    if(!who->query("super_fire",1))
     {
     say("任正晴道:你果然不負我所期望，完成這艱難的任務!!\n"
         "好!!這是瀧山拳禁斷技的奧密就傳授給你吧!!,望你更上一層樓。\n");
     who->set("super_fire",1);
     who->set("title","瀧山絕學傳人");
      who->set("go_ya",1);
     }
  }
}

int accept_fight(object who)
{
 command("say 果然英雄出少年。\n");
 who=this_player();
 fight_ob(who);
 command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
// command("perform force.kang-power");
  return 1;
}

int accept_kill(object who)
{
 command("say 找死!!!\n");
 who=this_player();
 kill_ob(who);
 command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
// command("perform force.kang-power");
  return 1;
}
  void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="fighter")
        {
                command("sigh");
                command("say 你不是武者﹐我不能收你。\n");
                return;
        }
      if((int)ob->query_cps() <20 )
{
          command("sigh");
          command("say 學瀧山拳法必須有恆心，敝人觀之"+ RANK_D->query_respect(ob) + "的資質似乎不宜！\n");

return;
        }

      command("hmm");
      command("pat" + ob->query("id"));
      command("recruit "+ob->query("id"));
}

// by babe
void heart_beat()
{
        if( !is_fighting() ) {
                if( query("sen") < query("eff_sen") ) // 125
                        command( "exert refresh" );
                if( query("force") < query("max_force") ) // 1 -> 5.035
                        command( "ex 160" );
                if( query("eff_kee") < query("max_kee") ) // 35
                        command( "10 exert heal" );
                if( query("gin") < query("eff_gin") ) // 125
                        command( "exert regenerate" );
                if( query("kee") < query("eff_kee") ) // 125 -> 300
                        command( "3 exert recover" );
        
        }
		if(is_busy() ){
		if(30>random(100)){
		message_vision(HIW + "\n只見$N暴起所有" + HIY + "真氣內勁" + HIW + "，$N全身隴罩在一股" + HIC + "綻藍氣勁" + HIW + "中，赫然已解開身上被封的穴道。\n" + NOR,this_object());
        delete_busy();
		}
		}
		::heart_beat();
}

string ask_yan()
{
  object me;
  me=this_player();
  if( me->query("fyan")==5)
{
command("say 您說風青雲前輩ㄚ,昨天他曾來找我商量欲借我隴山與劉全書雪蒼之力,以對付血魔龐大的勢力,談完後..他就往雪蒼去了。\n ");
me->set("fyan",6);
}
  else
    {
   command("say 我不清處呦~。\n");
    }
}

string test()
{
 object me;
 me=this_player();
 if(me->query("family/family_name") != "瀧山派")
  {

   return "任正晴怒道:不是瀧山弟子問那怎麼多做什麼!!!!\n";
  }
 if(me->query_skill("lungshan",1)   < 70)
  {
   return "任正晴怒道:瀧山派的武學都沒有學好了,還想學什麼禁技!!!\n";
  }
 say("任正晴沈吟一下!!!\n");
 say("任正晴道:最近中央譯站往平南城的方向,聽說有一隻獨角虎橫行,危害許\無數的百姓!!\n");
 say("任正晴續道:只要你除此大害!!我就將禁技傳授給你!!!\n");
 me->set("lungshan_test",1);
}
string kee_god()
{
 object me;
 me=this_player();
 if(!me->query("ask_god_kee"))
  {
   return "任正晴道:此事是武林中重大秘傳!!恕難奉告!!!!\n";
  }
 say("任正晴沈思了一下!!!\n");
 say("任正晴道:獨孤雲既然都跟你說了..我就告訴你吧!!\n");
 say("任正晴續道:仙雲之氣在天靈谷之中,但要進天靈谷必須要有青龍之氣及天靈石才能進!!\n");
 say("任正晴又道:至於天靈谷的位置的話!!在雪蒼山之中自己找吧!!\n");
 me->set("ask_god_kee",2);
}
string super_fighter()
{
 object me;
 me=this_player();
 if((me->query("class") != "fighter") || (!me->query("ask_super_fighter")) )
  {
   return "任正晴道:此地為武者傳說聖地,恕難奉告!!!!\n";
  }
 if((me->query("family/family_name") == "瀧山派") && (me->query("title") != "瀧山奧義傳人"))
  {
   return "任正晴怒道:連自己門派的秘奧義都沒有學會了,問那麼多做什麼!!!\n";
  }
 if((me->query("family/family_name") == "雪蒼派") && (me->query("title") != "雪蒼絕學傳人"))
  {
   return "任正晴怒道:連自己門派的絕學都沒有學會了,問那麼多做什麼!!!\n";
  }
 say("任正晴沈思了一下!!!\n");
 say("任正晴吟詩道:------雪~山~深~嶺~中、蒼~天~一~柱~峰-----\n");
 say("任正晴續道:下二句你就去問劉全書吧。!!\n");
 say("任正晴最後道:句中的涵意就自己體會吧。!!\n");
 me->set("ask_super_fighter",1);
}
void die()
{
	object winner = query_temp("last_damage_from");
	int j;
        if(!winner)
	{
	::die();
	return ;
        }
	tell_object(users(),"\n\t～～長江後浪推前浪 前浪死在沙灘上～～\n"+
	"\n\t想不到瀧山掌門任正晴竟被擊敗,看來武林將以"+winner->query("name")+"為至尊了!!\n");
/*        if(userp(winner)) {
	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj3/fire_feather")->move(environment(winner));
	  message_vision(HIM + "\n從任正晴的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/fire_feather",sprintf("%s(%s) 讓任正晴掉下了火之焰羽於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj3/fire_feather")->move(environment(winner));
	  message_vision(HIM + "\n從任正晴的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/fire_feather",sprintf("%s(%s) 讓任正晴掉下了火之焰羽於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
        }*/
 :: die();
}
