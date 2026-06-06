// 增加少林廚藝學院的quest相關 2010/09/06 by blazakira
//本quest 分為非少林(限制exp 500以上才可以解) 少林可以直接解
#include <ansi.h>
inherit NPC;
string eat();
string ask1();
string ask2(); //作為第一道菜的基本判斷
//string ask3(); //預計作為第二道菜的基本判斷
string bonze_food();

void create()
{
        set_name("少林大廚",({"chef"}));
        set("nickname","廚藝學院籌備中");
        set("long","他是少林伙房裡面的大廚，你看他態度嚴謹地到處巡視哪個伙房工在偷懶，你可以跟他要吃的(eat)。\n");
        set("gender","男性");
        set("combat_exp",500000);
        set("attitude","peaceful");
        set("age",45);
        set("inquiry",([
              "eat"         :(:eat:),
              "美味佳餚"    :(:bonze_food:),
              "少林廚藝學院":(:ask1:),
              "夢想"        : "我的夢想呀～那就是舉辦一個學院將一身所學的廚藝傳承下去——",
              "學院"        : "名字我跟二廚在那風光明媚的日子下想好了，那就是少林廚藝學院！",
              "砍柴"        : "這件事情不歸我管。\n",
              "挑水"        : "小事問二廚好了。\n",
              "苦惱"        : "難道大俠【願意】幫助我們？",
              "願意"        : "那太好了，原因是我們缺乏【食材】，所以心有餘力不足呀。",
              "食材"        :(:ask2:),
              "豆腐"        : "聽說某個世外桃源裡的小姑娘有著豆腐西施之美名。",
              "絞肉"        : "聽說某個地方的小二私下販賣靠著關係所拿到上等肉類製作而成的絞肉。",
              "烈酒"        : "聽說某位紅鼻子前輩釀得一手好酒。",
              "調味料"      : "聽說某位大俠的父親世代種植著獨一無二的辣椒。",
              ]));

        set("class","bonze");
        set_skill("unarmed",45);
        set_skill("stick",90);
        set_skill("dodge",70);
        set_skill("parry",70);
        set("chat_chance", 100);
        // 平時會自動出現的訊息
        // 可以包括副程式及訊息
        // 補充一下 combat_msg是用來戰鬥時mob所參生的訊息......	
        set("chat_msg",({
        (: random_move :),
        (: random_move :),
        (: random_move :),
        "少林大廚說道﹕我有一個夢想，那就是能有個地方可以將一身廚藝傳承下去…\n",
        }));
        set_temp("quests/bonze/stop",1); //設定為阻擋npc離開房間
        setup();
        add_money("silver",8);
        carry_object("/open/bonze/obj/club")->wield();
}

void init()
{
  set_heart_beat(1);
  ::init();
}

string eat()
{
  object me = this_player();
  if(me->query("class") != "bonze")
    return "對不起，這裡只提供齋菜給少林師父哦！ ";
  if(me->query_temp("need_food")+15*60*60 > time())
    return "剛已經拿給你了，這裡有很多人還要吃呢，你等等再來。";
  me->set("food",me->max_food_capacity());
  me->set("water",me->max_water_capacity());
  me->set_temp("need_food",time());
  return "來吧，這些是$N要吃的齋菜，$N就慢慢吃吧。";
}

string ask1()
{
  object me = this_player();
  me->set_temp("quests/bonze/food/start",1);
  return "【苦惱】呀～該不會開不成了吧，那是吾輩廚師一生的夢想呢，唉～";
}

string ask2()
{
  object me = this_player();
  if(me->query_temp("quests/bonze/food/start") == 1)
    return "我們想推出的第一道佳餚尚缺少【豆腐、絞肉、烈酒、調味料】這些食材。";
  return "你在問什麼我怎麼聽不懂。"; //食材任務判斷失敗時
}

string bonze_food()
{
  object me = this_player(),ob,obj;
  int i,j;
  j=(int)(random(me->query("per"))/5+3);
  if (j>10) { j=10; } //限定最大值
  if( wizardp(me) ) { message_vision(HBBLU"測試 給予的數量為【"+j+"】\n"NOR,me); } //給巫師看的

  if(me->query_temp("quests/bonze/food/finish") == 1) { //第一道菜
    me->delete_temp("quests/bonze/food/finish"); //理論上此時應該只有一個食材任務所以刪除應不會有其他影響
    for (i=0;i<j;i++) //第一個參數為起始數字 第二個得設定範圍而非單純給予數字 第三個為遞增 此為三個條件判斷
    {
      ob=new("/open/bonze/food_quest/mapodoufu"); //麻婆豆腐
//      ob->set_amount(); //由於此料理為 inherit ITEM 模組 所以無法設定數量
      ob->move(me);
    }

/* 此段作為增加數量的參考 於本次不能直接堆疊(set_amount() add_amount())的道具無效 by blazakira
    ob = present("mapo doufu",me); //需判斷玩家身上是否已經持有 避免重複解的時候 被覆蓋
    if (!ob) //ob為指定玩家身上的道具 obj為指定給予道具的變數
    {
      message_vision("測試1\n",me);
      ob=new("/u/b/blazakira/bonzee/lion_quest/obj/food_quest/mapodoufu"); //麻婆豆腐
      ob->set_amount(10);
      ob->move(me);
    }
    else {
      message_vision("測試2\n",me);
      ob->add_amount(10);} //這的ob已在上面宣告為玩家身上的道具了所以直接加就好
*/
  }
  else if(me->query_temp("quests/bonze/food/finish") == 2) { //第二道菜 此食材任務尚未完成 所以不可能會觸發 於此先行紀錄 以免將來忘記
    me->delete_temp("quests/bonze/food/finish"); //理論上此時應該只有一個食材任務所以刪除應不會有其他影響
    for (i=0;i<j;i++)
    {
      ob=new("/open/bonze/food_quest/rice"); //蝦仁蛋炒飯
      ob->move(me);
    }
  }
  else return "噗，大俠你在說什麼呀。";
  return "請大俠一邊享用這道佳餚一邊在武學之道上走得更遠吧。";
}

int accept_object(object who, object ob)
{
  string food_obj;
  food_obj=ob->query("id"); //ob為接受的道具 應可直接判斷是否有temp的mark 此處只取ob的id
//目前暫定本npc接受第一道菜全部的食材
  if (food_obj == "meat" && who->query_temp("quests/bonze/food/meat") !=2) {
    ob->set_temp("quests/bonze/food",1);} //絞肉為例外的道具 所以為了下句的判斷 因此額外增設本行
  if (!ob->query_temp("quests/bonze/food")) { //本判斷含有收到非正常食材時的反應
    tell_object(who,"你確定你拿給我的是新鮮的食材嗎？\n");
    return 1;}
//即便重複收到道具也不予理會
  switch (food_obj){
  case "tofu":
       command("nod "+who->query("id"));
       who->set_temp("quests/bonze/food/tofu",2);
	   break;
  case "pepper":
       command("nod "+who->query("id"));
       who->set_temp("quests/bonze/food/pepper",2);
	   break;
  case "liqueur":
       command("nod "+who->query("id"));
       who->set_temp("quests/bonze/food/liqueur",2);
	   break;
  case "meat":
       command("nod "+who->query("id"));
       who->set_temp("quests/bonze/food/meat",2);
	   break;
  default :
       break;
  }
       destruct(ob);
//在此做是否全部收集完的判斷 應可解決給完所有食材後 沒有任何反應得再給予道具的bug
  if (who->query_temp("quests/bonze/food/liqueur") == 2 
       && who->query_temp("quests/bonze/food/meat") == 2
       && who->query_temp("quests/bonze/food/tofu") == 2
       && who->query_temp("quests/bonze/food/pepper") == 2
       ) {
       command("cong "+who->query("id"));
       command("say 請大俠稍等一會，待我與二廚合力完成這道【美味佳餚】吧。");
       who->delete_temp("quests/bonze/food"); //刪除已收集食材的temp 收集食材的任務同時間只允許一件
       who->set_temp("quests/bonze/food/finish",1); //與上行順序不可交換 此為收集食材任務完成的mark 此為第一道菜的mark=1
    }
  else {command("say 很好，這份食材我收下了，大俠你繼續努力。");}
  return 1;
}
