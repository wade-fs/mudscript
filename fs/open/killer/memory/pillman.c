#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit SSERVER;
string black();
string spill();

string spill()
{
  if ( !present("herb",this_player()) )
    return "沒有富士山秘草，你要我煉什麼？\n";
  this_player()->set_temp("herb_1",2);
  return "想煉藥就把東西交給我吧!!\n";
}

string black()
{
  if (this_player()->query_temp("mission2") !=1)
    return "賒！賒！你講賒？只要熱開水？";
  this_player()->set_temp("kill_fu",1);
  return "那個混進來的金刀門混蛋，把她身上的香包給我，我就告訴你";
}
  
string hate()
{
object me=this_player();
  if (this_player()->query_temp("memory") !=2)
  {
	command("say 不要煩我，快滾");
    message_vision(HIR + "只見婆婆一掌將你打飛\n" + NOR);
	this_player()->add("kee",-50);
	this_player()->move(__DIR__"floorm.c");
             return "仇什仇？老身從不跟人結仇的";
  }
 message_vision(HIY + "那是黑牙聯的一件往事了.....\n" + NOR,me);
 message_vision(HIY + "當時，本名渡永天的天靈老鬼，他與孤城是非常要好的朋友\n" + NOR,me);
 message_vision(HIY + "但是兩人卻同時喜歡上婆婆我\n" + NOR,me);
 command("blush");
 message_vision(HIY + "兩人陷入了前所未有的尷尬情形，但是我卻無法決定心所屬誰\n" + NOR,me);
 message_vision(HIY + "然而關鍵是在某個事件中，那就是完顏宏烈的叛變事件中\n" + NOR,me);
 message_vision(HIY + "原本想暫時離開總壇，與柴榮去修練更高的技巧的孤城\n" + NOR,me);
 message_vision(HIY + "其實，是因為想釐清三人之間的關係，所以才離開總壇的\n" + NOR,me);
 message_vision(HIY + "然而，這時卻發生叛變事件，使得黑牙聯與魔教陷入交戰的危機\n" + NOR,me);
 message_vision(HIY + "不得不出面解決這一件事件，但是卻與渡永天他起了爭執\n" + NOR,me);
 message_vision(HIY + "因為他認為，要先逼完顏宏烈交出天魔解體大法，才解決他\n" + NOR,me);
 message_vision(HIY + "然而，柴榮本身因為被完嚴宏烈陷害，形成此一事件的主角\n" + NOR,me);
 message_vision(HIY + "而孤城他為了維護他，便想先殺完嚴宏烈，將其交給魔教\n" + NOR,me);
 message_vision(HIY + "於是兩人便在後山那裡打了起來，正當兩人打的火熱之時\n" + NOR,me);
 message_vision(HIY + "這個髮箍射中孤城，這時孤城以為是我暗中幫助渡永天\n" + NOR,me);
 message_vision(HIY + "便無心戀戰，而轉身離去..........\n" + NOR,me);
 message_vision(HIY + "這根本是完嚴宏烈設下的陷阱，他從我身邊偷走髮箍，並且下毒\n" + NOR,me);
 message_vision(HIY + "使得孤城他受傷嚴重，不得不把權力交給葉秀殺\n" + NOR,me);
 message_vision(HIY + "而我也在照顧孤城的過程中，將誤會冰釋並與孤城陷入的戀情之中\n" + NOR,me);
 message_vision(HIY + "而那把髮箍也成了我兩之間的信物，但好景不常.....\n" + NOR,me);
 message_vision(HIY + "渡永天竟將髮箍偷走，在偷偷把它丟在自己的床邊n" + NOR,me);
 message_vision(HIY + "在引孤城去看，暗示我紅杏出牆........\n" + NOR,me);
 message_vision(HIY + "孤城一怒之下，也找我問清楚，便遠走東瀛\n" + NOR,me);
 message_vision(HIY + "我便一路追趕了過去，但是卻沒有追上，我在東瀛找了五年後\n" + NOR,me);
 message_vision(HIY + "並沒有任何音訊，也只有回到總壇之中，\n" + NOR,me);
 message_vision(HIY + " 這時，渡永天早已因輔助葉秀殺，而成為殺手的第二勢力者  \n" + NOR,me);
 message_vision(HIY + "我也不願將此事公開，於是我就從殺手的第一線工作退了下來   \n" + NOR,me);
 message_vision(HIY + "這事便成為了無頭公案，孩子，你願意幫我一個忙嗎？   \n" + NOR,me);
 message_vision(HIY + "你幫我到那賤人住的附近的湖中找一條大鯉魚  \n" + NOR,me);
message_vision(HIY + "當年孤城離開時，曾經留書說有東西在此魚腹中，要我去找   \n" + NOR,me);
message_vision(HIY + "但我一直找不到，這幾年因為他搬回總壇，我也沒再去找了   \n" + NOR,me);
this_player()->set_temp("memory",3);
 return "少年的，如果找到的話，婆婆會有你的好處的.....";
}

int accept_object(object wo,object ob)
{
  object me,ob2,ob3;
  
  me=this_player();

  if(ob->query("id") == "hair")  //往事之謎     
  {
    if (this_player()->query_temp("memory") != 1)
    {
	command("say 給我這個幹嘛！");
             destruct(ob);
      	return 0;
    }
    command("sm "+this_player()->query("id"));
    command("say 你從哪裡拿到的？是不是從天靈老人那理拿到得？\n");
    command("say 可惡，那老鬼以為將這個交還給我，就可以化解(仇恨)嗎？");
    me->set_temp("memory",2);
    destruct(ob);
    return 1;
  }

  if(ob->query("id") == "special can")  //往事之謎的打死魚之後的劇情
  {
    if (this_player()->query_temp("memory") < 7)
    {
	command("say 小鬼，魚你是請別人殺的對不對？  沒收！");
	 destruct(ob);
      	return 0;
    }
    command("spank "+this_player()->query("id"));
    command("say 這是早期孤城專用的傳令筒");
    message_vision(HIG + "婆婆接過竹筒後以特殊的手法將竹筒打開\n從裡面拿出一張羊皮紙n" + NOR,me);
    message_vision(HIG + "婆婆緩緩的端詳了裡面所記載的事情，隨後嘆了一口氣.....\n" + NOR,me);
    command("say 永天，看來是我誤會你了............");
    message_vision(HIM + "之後，婆婆將事情的源由緩緩道來....，在婆婆解說下，才知道\n" + NOR,me);
    message_vision(HIM + "原來當年是完嚴宏烈所設下的陷阱，想要引起兩人之間的征戰\n" + NOR,me);
    message_vision(HIM + "葉孤城將計就計想引出完嚴宏烈，便離開總壇看他是否會暗殺葉孤城\n" + NOR,me);
    message_vision(HIM + "但是，完嚴宏烈並沒有上當，原本想要再次回到總壇。\n" + NOR,me);
    message_vision(HIM + "不過在與渡永天討論過後，感到東瀛的勢力，似乎逐漸滲透中土\n" + NOR,me);
    message_vision(HIM + "並且發現有不少人已經成為各派的第二，三代傳人，但是不知到有哪些人\n" + NOR,me);
    message_vision(HIM + "根據寧錯殺不放過，於是便與渡永天定下殲滅各派第二，三代傳人的計畫\n" + NOR,me);
    message_vision(HIM + "因為事關重大，為避免打草驚蛇，葉孤城便遠走東瀛，順便找裝備與情報\n" + NOR,me);
    message_vision(HIM + "而渡永天也不便向葉玲如說明，也不刻意去找出完嚴宏烈\n" + NOR,me);
    message_vision(HIM + "才會形成目前的情形.......\n" + NOR,me);
    command("say 小朋友，多謝你幫忙婆婆，這個令牌你拿去，順便去找渡永天他會給你好處的");
    message_vision(HIR + "婆婆交給你一面令牌\n" + NOR,me);	
     ob3=new("/open/killer/memory/card.c");
     ob3->move(me);
    me->set_temp("memory",8);
   destruct(ob);

    return 1;
  }

 if(ob->query("id") == "fu_page") //黑血神針之謎的香包
  {
    command("grin "+this_player()->query("id"));
    command("say 果然夠狠，足夠出這個任務\n");
    command("say 其實也很簡單，在三樓東邊的裝備室，就有葉孤城當年留下來的血變之牙");
    command("say 不會開呀？相信我，現在你再去，就能開了，這是婆婆的庇佑：P");
    command("say 你只要再向李三笑那個老鬼，（借幽冥之壺）就可以了。");
    me->set_temp("mission2",2);
     destruct(ob);
    return 1;
  }

  if(ob->query("id") == "ghost can")
  {
    if (me->query_temp("mission2") == 4)
    {
      if (me->query_temp("tt")==1)
      {
       command("say 你等一下，我煉製一下，馬上就好了");
       message_vision(HIR + "婆婆躲入密室後，密室中呼喊聲不斷，非常淒瀝\n" + NOR,me);
       message_vision(HIR + "過了一會，婆婆拿了一盒，金色的護具\n" + NOR,me);
       ob2=new("/open/killer/obj/black.c");
       ob2->add_amount(14);
       ob2->move(me);
       command("say 裡面就是黑血神針，小心一點，不要反而傷了自己");
       command("bye "+me->query("id"));
       me->set_temp("mission2",0);
      }
      else
      {
        command("say 血變之牙呢？");
        me->set_temp("can",1);
      }
      destruct(ob);
      return 1;
    }
    else
    {
      command("say 給我這個幹嘛！");
 destruct(ob);

      return 0;
    }
  }

  if(ob->query("id") == "blood change")
  {
    if (me->query_temp("mission2") == 4)
    {
      if (me->query_temp("can")==1)
      {
       command("say 你等一下，我煉製一下，馬上就好了");
       message_vision(HIR + "婆婆躲入密室後，密室中呼喊聲不斷，非常淒瀝\n" + NOR,me);
       message_vision(HIR + "過了一會，婆婆拿了一盒，金色的護具\n" + NOR,me);
       ob2=new("/open/killer/obj/black.c");
       ob2->add_amount(14);
       ob2->move(me);
       command("say 裡面就是黑血神針，小心一點，不要反而傷了自己");
       command("bye "+me->query("id"));
       me->set_temp("mission2",0);
      }
      else
      {
        command("say 幽冥之壺呢？");
        me->set_temp("tt",1);
      }
     destruct(ob);
      return 1;
    }
    else
    {
      command("say 給我這個幹嘛！");
      destruct(ob);
      return 0;
    }
  }

  if(ob->query("id") == "herb")
  {
   switch (me->query_temp("herb_1"))
   {
     case 0 :
     {
      command("say 唉。。我不是說過，隨便拿來的富士山秘草是沒有用的！\n");
      me->set_temp("herb_1",0);
      return 0;
     }
     case 1 :
     {
      command("say 浸也不浸久一點，根本沒入味嘛！\n");
      me->set_temp("herb_1",0);
      return 0;
     }
     case 2 :
     {
      destruct(ob);
      command("say 沒錯就是這樣，真好！！你等一下，我立刻就好。。。\n");
      message_vision(HIR + "只見婆婆熟練的動作，將草藥放入爐中\n" + NOR,me);
      message_vision(HIR + "不一會兒，數顆殺手密藥就已經做好了\n" + NOR,me);
      ob2=new("/open/killer/obj/s_pill.c");
      ob2->add_amount(14);
      ob2->move(me);
      command("say 好啦，拿去吧。。好好為黑牙聯盡一份心力哦。");
      command("bye "+me->query("id"));
      me->set_temp("herb_1",0);
      return 1;
     }
    }
  }
  command("? "+this_player()->query("id"));
  command("say 呵。。。你在送禮嗎？\n");
  return 0;
}  
void create()
 {
  object ob;
  set_name("葉玲如",({"old woman","old","woman"}) );
  set("long","千萬不要看她的外表，而輕易對她下毒手。她可是超級殺手哦。\n");
  set("race", "人類");
  set("gender","女性");
  set("combat_exp",101010);
  set("age",66);
  set("title","神秘煉藥婆婆");
  set("class","killer"); 
  set("str",30);
  set("cor",30);
  set("cps",30);
  set("kee",500);
  set("max_kee",500);
  set("force",100);
  set("max_force",100);
  set("force_factor",3);
  set("bellicosity",150);
  set("inquiry",([
      "富士山秘草" : "你有嗎？不是隨意拔來就可以用。我會煉成（殺手密藥）\n",
      "仇恨" : (: hate :),
      "殺手密藥" : (: spill :),
      "黑血神針" : (: black :),
      ]));
  setup();
 add_money("gold",5); 
 ob=carry_object("/open/killer/obj/lustar");
 ob->add_amount(1000); 
 ob->wield();
 carry_object("/open/killer/weapon/k_arm1.c")->wear();
 carry_object("/open/killer/weapon/k_belt1.c")->wear();
 carry_object("/open/killer/weapon/k_cloth1.c")->wear();
 carry_object("/open/killer/weapon/k_coat1.c")->wear();
 carry_object("/open/killer/weapon/k_leg1.c")->wear();
 carry_object("/open/killer/weapon/k_torch.c")->wear();
}

void init()
{
    object ob;
    ::init();
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1,ob);   }
}

int accept_kill(object ob)
{
  message_vision( this_object()->name()+"你怎麼要殺我？.....：~\n",ob);
  command("say 令人憤怒的傢伙。。。孤城賜給我對抗的力量吧");
  this_object()->set("combat_exp",650000);
  this_object()->set("max_force",1800);
  this_object()->set("gin",2000);
  this_object()->set("sen",2000);
  this_object()->set("max_kee",3000);
  this_object()->set("kee",3000);
  this_object()->set("eff_kee",3000);
  this_object()->set("force",1800);
  set_skill("dodge",85);
  set_skill("move",75);
  set_skill("parry",75);
  set_skill("throwing",80);
  set_skill("rain-throwing",70);
  set_skill("shade-steps",85);
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
  this_object()->set("title","超級殺手煉藥師");
  command("say 敢在此撒野？讓你看看我的利害！！");
  command("wield star");
  this_object()->kill_ob(this_player());
    return 1;
}

int accept_fight(object me)
{
    command("say 呵。。。老身可沒時間陪你玩");
    command("waggle "+this_player()->query("id"));
    return 0;
}

void greeting(object ob)
{
  if(this_player()->query("id")=="wataru")
  {
   command("say 哇....天才小渡來了，好高興！！");
   command("kiss wataru");
  }
  else
  { command("smile "+this_player()->query("id"));}
}   
