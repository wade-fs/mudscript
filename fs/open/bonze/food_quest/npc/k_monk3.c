// 增加少林廚藝學院的quest相關 2010/09/06 by blazakira //人氣不高 所以未完成 暫時開放為挑水quest npc
// 挑水quest紀錄在玩家身上 解quest的每一次都紀錄(遞增) 同時紀錄時間 用來比對解quest的間隔 吃了pill也紀錄
//log(file, message)

#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
inherit NPC;
string eat();
string bonze_food();
string bonze_quest_water();

void create()
{
        set_name("少林二廚",({"sous chef","chef"}));
        set("nickname","廚藝學院籌備中");
        set("long","他是少林伙房裡面的二廚，你看他態度嚴謹地到處巡視哪個伙房工在偷懶，你可以跟他要吃的(eat)。\n");
        set("gender","男性");
        set("combat_exp",500000);
        set("attitude","peaceful");
        set("age",41);
        set("inquiry",([
              "eat"         : (:eat:),
              "夢想"        : "夢想？有點不好意思說，那就是…跟著大廚舉辦一個學院教這些弟子就好。",
              "學院"        : "名字我跟大廚想好了，那就是少林廚藝學院！",
              "砍柴"        : "現在不缺木頭。",
              "挑水"        : "真是奇怪，以前不會有這樣的糾紛耶，真搞不懂現在的年輕弟子在想些什麼。",
              "心結"        : (:bonze_quest_water:),
              "苦惱"        : (:bonze_quest_water:),
              "糾紛"        : (:bonze_quest_water:),
//              "佳餚"        : (:bonze_food:),
//              "美味佳餚"    : (:bonze_food:)
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
        (: random_move :),
        "少林二廚說道﹕大廚的夢想就是吾輩的夢想…\n",
        "少林二廚說道﹕現在的年輕弟子究竟有什麼心結呀，挑水而已有什麼好苦惱的。\n",
        HIY + "少林二廚說道﹕誠心提醒施主，遊戲歸遊戲，不要太著相了。\n" + NOR,
        }));
        set_temp("quests/bonze/stop",1); //設定為阻擋npc離開房間
        setup();
        add_money("silver",6);
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

/*
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
  if( wizardp(me) ) { message_vision(HBBLU + "測試 給予的數量為【"+j+"】\n" + NOR,me); } //給巫師看的

  if(me->query_temp("quests/bonze/food/finish") == 1) { //第一道菜
    me->delete_temp("quests/bonze/food/finish"); //理論上此時應該只有一個食材任務所以刪除應不會有其他影響
    for (i=0;i<j;i++) //第一個參數為起始數字 第二個得設定範圍而非單純給予數字 第三個為遞增 此為三個條件判斷
    {
      ob=new("/open/bonze/food_quest/mapodoufu"); //麻婆豆腐
//      ob->set_amount(); //由於此料理為 inherit ITEM 模組 所以無法設定數量
      ob->move(me);
    }
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
}*/

string bonze_quest_water() //目前挑水所發的獎勵採隨機
{
  object me = this_player(),ob = this_object(),obj;
  string *gift1,*gift2;
  int i,j;
  j=random(7)+3;
  gift1 = ({
    "magic",
    "sword",
    "blade",
    "stabber",
    "staff",
    "throwing",
    "unarmed",
    "whip",
    "dagger",
    "dodge",
    "force",
  });
  gift2 = ({
    "spells",
    "move",
    "parry",
  });
//交給房間做同時消除("quests/bonze/water/stop")的判斷也是個方法
//兩個方式的獎勵優先判斷才不會讓人有等很久的感覺
  if ( query("quests/bonze/water/stop") && me->query_temp("quests/bonze/water/method1") == 1 && me->query("quests/bonze/water/start") >1 ) { //先做是否有人打死挑水和尚的判斷 且詢問者是否就是兇手:p
    for (i=0;i<j;i++)
    {
      obj=new(BONZE_OBJ"basesk_p.c");
      obj->set("種類",gift2[random(sizeof(gift2))]);
      obj->move( me );
    }
    me->delete_temp("quests/bonze/water/method1"); //領過獎勵就該解除mark //以前沒解完時 允許完成該quest後 再解一次 //不想搞得很嚴肅
	me->delete("quests/bonze/water/start");
    me->add("quests/bonze/water/method1",1); //紀錄解謎方式與次數
    if ( !me->query("quests/bonze/water/finish") ) {
      me->set("quests/bonze/water/finish",1); } //作為 指令：quests 查驗用
    message_vision("$n從懷裡掏出個錦囊，從中拿出了數顆丹藥交給了$N。\n",me,ob);
    return "不是很鼓勵施主使出這種手段，但施主仍舊是幫了少林寺上下一個忙，因此這是一點薄禮。";
  } //解謎過的玩家 次數達某個程度後 取得解謎的獎勵步驟後 於此給予獎勵
  else if ( me->query_temp("quests/bonze/water/times") > 6 && me->query_temp("quests/bonze/water/method2") >2 && me->query("quests/bonze/water/start") >1 ) { //為達成協助挑水任務的次數
    j=random(20)+10;
    for (i=0;i<j;i++)
    {
      obj=new(BONZE_OBJ"basesk_p.c");
      obj->set("種類",gift1[random(sizeof(gift1))]);
      obj->move( me );
    }
    me->delete_temp("quests/bonze/water/method2");
//    me->delete_temp("quests/bonze/water/times"); //關閉 為了檢驗次數時 可以參考 此外 已在接任務的三位和尚中歸零了
	me->delete("quests/bonze/water/start");
    me->add("quests/bonze/water/method2",1);
    if ( !me->query("quests/bonze/water/finish") ) {
      me->set("quests/bonze/water/finish",1); }
    message_vision("$n從懷裡掏出個錦囊，從中拿出了數顆丹藥交給了$N。\n",me,ob);
    return "很高興施主是個大毅力之人，一點小小薄禮不成敬意。";
  } //有人打死和尚時 解謎功能延後30分鐘
  else if ( query("quests/bonze/water/stop") && query("quests/bonze/water/time")+30*60 > time() ) { //query("quests/bonze/water/time")在二廚身上紀錄時間 //設小於的邏輯判斷 是符合條件後 且這段時間內詢問都不能解謎的意思
    return "對不起，目前不缺人手喔，請三十分鐘後再來詢問吧。";
  } //對於解過的玩家重複解謎的間隔為59分鐘
//  if ( me->query("quests/bonze/water/time")+59*60 < time() && me->query("quests/bonze/water/start") >0 ) //大於紀錄時間的59min後 才允許重解
  else if ( me->query("quests/bonze/water/time")+59*60 > time() ) { //大於紀錄時間的59min後 才允許重解 //隨著時間經過 超時後 右邊大於左邊 所以if不成立
    return "大善，施主這麼熱心幫助本寺，貧僧在此向您道謝。";
  }
  me->set("quests/bonze/water/time",time());
  me->set("quests/bonze/water/start",1); //quest開始 不設temp 因為quest有限時間 59min之內無須重複詢問 //設temp 則會因為離線導致需要重複詢問時 卻不能問
  return "我聽說阿大、阿二、阿三，三位師弟彼此有心結，導致本寺的飲用水不足，就請施主幫貧僧找出解決的方法好嗎。";
}
