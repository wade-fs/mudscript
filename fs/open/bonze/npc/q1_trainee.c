//s_monk.c
/*
一個和尚挑水喝、兩個和尚抬水喝、三個和尚沒水喝。
以前有聽過一個小故事：有一間寺廟住著一個和尚。當沒水喝時，他就自己下山挑水
回來；後來來了一個和尚，要喝水時就兩人一起下山抬水回來，誰都不吃虧。之後又
來了一個和尚，碰到沒水的時候該由誰下山挑水呢？一跟扁擔兩個頭，所以你看我我
看你誰都不想去，所以到最後誰都沒水喝!

徒兒 阿大 阿二 阿三(暫定名稱 有些煩惱 你不妨幫他們一下
方案一 殺死一個...>壞結果 低獎勵
方案二 自己幫忙提水 ...>好結果 高獎勵

流程
三個人 任一個人都可以取得任務水桶以便觸發任務
當然可以殺死其中一人以觸發兩個和尚抬水喝的路線
為 殺死之後在玩家身上做mark紀錄 然後到其他兩位的面前
餘下任一位 先觸發心裡壓力=逃跑 因為殺手凶悍來到面前 所以膽小跑去挑水
然後接觸最後一位才算完成抬水喝的路線 此部份分別在void die() 與 void greeting() 裡紀錄與判定 當然此路線可作為隱藏路線而設定
正經八百的流程就是幫忙挑水 次數需拉長(累積) 或者將每次需求的次數不一 需要玩家多重複此次挑水的過程

方法一 殺死一人 大廚的說詞 不是很鼓勵施主使出這種手段 但是施主仍舊是幫了少林寺上下一個忙 因此不得不給施主一個獎勵
主持說 真是奇怪 最近本寺的飲用水?短缺 貧僧因為後山xx 因而走不開 能否煩請施主替貧僧去看看是發生什麼問題好嗎?
*/

#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
inherit NPC;
string ask_job();
string ask_dispute();
string ask_bucket(); //需補充一個因為離線 所導致的quest無法完成的情況
void create()
{
  object obj;
  set_name("阿大",({"janitor one","one"}));
  set("title","少林雜役弟子");
  set("long","他為了在學習少林武功\前打下深厚的基礎而每天挑水砍柴。\n");
  set("gender","男性");
  set("combat_exp",80000);
  set("attitude","peaceful");
  set("age",16);
  set("class","bonze");
  set_skill("unarmed",35);
  set_skill("dodge",20);
  set_skill("parry",30);
  set("chat_chance", 80);
  set("chat_msg", ({ //改正面? 大家都想去 大家都想分擔 只是沒有理解的分工合作 導致一開始大家選擇都一樣而忘記還有其他工作要做?
    (: random_move :),
    (: random_move :),
    (: random_move :),
    "阿大說道﹕怎麼會這樣呢，以前只有我在挑水的時候還不覺得複雜，怎人一多就…\n",
	"阿大說道﹕寺裡的水快用完了，我應該一個人去就好，雖然辛苦了點，唉～\n",
	"阿大說道﹕我是不是該獨自去挑水呢…\n",
	"阿大說道﹕一根扁擔兩個頭，只要他們其中一位讓一下就不會這麼麻煩了，唉～\n",
	"阿大說道﹕一根扁擔兩個頭，他們人太好了所以才會跟我爭挑水的工作，唉～\n",
	"阿大說道﹕唉～為什麼他們都不讓步呀…\n"}));
  set("inquiry", ([
	"心結"      : (: ask_dispute :),
	"苦惱"      : (: ask_dispute :),
	"糾紛"      : (: ask_dispute :),
	"砍柴"      : "少林後山林木繁盛但也得留薪火以待來者才行。\n",
	"挑水"      : (: ask_job :), //假使玩家離線則可以跳過前面的步驟 從此處開始解
    ]));
  set_temp("quests/bonze/stop",1); //設定為阻擋npc離開房間
  setup();
  set_temp("apply/attack", 4);
  set_temp("apply/damage", 1);
  set_temp("apply/armor", 3);
//  carry_object(BONZE_OBJ"bucket.c");
  obj=new(BONZE_OBJ"bucket.c");
  obj->set("no_steal",1); //作為quest媒介 所以避免萬一
  obj->set("no_get",1); //作為quest媒介 所以避免npc被打昏的情況
  obj->move(this_object());
  add_money("coin",20);
}

void init()
{
//需增設遇到進入方法一的玩家的判斷
  object ob=this_object();
  if ( ob->query("quests/bonze/water/stop") ) { //已經有人打死其他挑水和尚之一時 關閉解quest的功能 但是已經在挑水的玩家 預計不妨礙其完成
    ob->set("nickname","勤奮挑水的"); //此title只存在於不能解quest的期間
  }
  add_action("do_nod","nod");
  add_action("do_ok","ok");
  add_action("do_shake","shake");
  set_heart_beat(1);
  ::init(); //本::init();即呼叫預設的函數 ex:void greeting()之類的
}

void greeting(object who)
{
  object ob=this_object();
  if ( who->query_temp("quests/bonze/water/method1")==1 ) {//方法一 殺死和尚
    write(HIY + "阿大看見你時，緊張地快說不出話來﹕施…主，我、我…這就去…挑、挑水。\n只見他慌慌張張地拿起一旁的水桶後迅速離開你眼前。\n" + NOR);
//    environment(ob)->set("no_reset",1); //當有玩家使用方法一時 同時已在該npc重生的房間做延時rb的功能所以不須在greeting設定了
//    environment(ob)->start();
    command("flee "+who->query("id"));
    destruct(ob); //遇到殺死其他挑水和尚的玩家時 本npc因為害怕而逃離(destruct) 並且 啟動延時rb的功能(需與房間的函數相呼應)
  }
}

int accept_kill(object who)
{
  object ob;
  ob=this_object();
  if( ob->is_fighting() ) //如果在戰鬥中了就別吼了
    return 1;
  command("shout "+who->query("name")+"施主的心腸怎麼這麼狠毒！阿彌陀佛——");
  return 1;
}

int accept_fight(object who)
{
  message_vision("阿大對$N搖搖手指說﹕$N一邊玩去，和尚我快下定決心去挑水了。\n",who);
  return notify_fail("");
//  return 1;
}

string ask_dispute()
{
  object me = this_player();
  if ( !me->query("quests/bonze/water/start") ) //沒有開始就不理會玩家
    return "施主你著相了，吾輩少林弟子必須遵循不瞋、不貪、不癡等戒律。";
  me->set("quests/bonze/water/start",2); //解謎第一步
  return "施主有心了，我們師兄弟三人雖然沒有真正的吵起來，但是也相差不遠，起因是挑水的問題。\n一根扁擔兩個頭，因此我們僵持不下，這才導致無人挑水，罪過罪過。";
}

string ask_job()
{
  object me = this_player();
  if ( me->query("quests/bonze/water/start") <2 ) //沒有開始就不理會玩家
    return "嗯！這是一件不簡單的工作，藉以鍛鍊體魄與堅定心念才能秉持本心。";
  if ( this_object()->query("quests/bonze/water/stop") ) //已經有人打死其他挑水和尚之一時 關閉解quest的功能 但是已經在挑水的玩家 預計不妨礙其完成
    return "阿彌陀佛，施主有事嗎？";
  if ( me->query_temp("quests/bonze/water/method1") || me->query_temp("quests/bonze/water/method2")) //已選方法一或二時
    return "不知道有誰能夠幫忙或者出點主意也好？"; //重複提示 nod or shake
  me->set_temp("quests/bonze/water/method2",1); //方法二 挑水任務開始
  me->set_temp("quests/bonze/water/times",0); //任務重新開始就是歸零
  return "不知道該怎麼解決這件事，還是說施主願意指點或者能提供什麼幫助？";
}

int do_nod(string str)
{
  object ob = this_object() , me = this_player();
  object obj;
//  if ( me->query("quests/bonze/water/finish")==1 ) return 0; //此謎完成後 //避免離線 所以採固定mark 亦為了作為解謎間隔時間判定之一
  if ( !me->query_temp("quests/bonze/water/method2") ) return 0; //如果沒有開始解謎的動作就不回應
  if ( me->query_temp("quests/bonze/water/method1") >0 ) return 0; //如果進入解謎方法一時就不回應 並在init裡刪除本npc //此步驟為避免萬一 因為greeting()會先判斷
  if ( me->query_temp("quests/bonze/water/method2") >1 ) return 0; //只有當等於1時才會繼續下面的判斷
  command("say 這樣也好，那麼…就煩勞施主了，阿彌陀佛。");
  command("bow "+me->query("id"));
  if( !present("bucket",me) ) { //重複解的情況下有可能留在身上 所以不需重複給
    obj=new(BONZE_OBJ"bucket.c");
    obj->move( me );
    message_vision("$n拿起身旁的水桶交給了$N。\n",me,ob);
  }
  else {
    command("say 喔喔～既然施主身上已經有了水桶，和尚我就不多此一舉了，阿彌陀佛。");
  }
  me->set_temp("quests/bonze/water/method2",2);
  return 1;
}

int do_shake(string str)
{
  object ob = this_object() , me = this_player();
  if ( !me->query_temp("quests/bonze/water/method2") ) return 0; //如果沒有開始解謎的動作就不回應
  if ( me->query_temp("quests/bonze/water/method1") >0 ) return 0; //如果進入解謎方法一時就不回應 並在init裡刪除本npc //此步驟為避免萬一 因為greeting()會先判斷
  if ( me->query_temp("quests/bonze/water/method2") >1 ) return 0; //只有當等於1時才會繼續下面的判斷
  command("say 嗯嗯，既然施主覺得困擾的話，那麼請稍候有空閒時再過來看看好了，阿彌陀佛。");
  command("smile "+me->query("id"));
  me->set("quests/bonze/water/start",0); //歸零之後 需等1小時才能重解
  me->set_temp("quests/bonze/water/method2",0); //歸零之後 需等1小時才能重解
  return 1;
}

void die()
{
  object winner=query_temp("last_damage_from");
  object ob=this_object();
//暫時開放為全部門派都可以解 暫定將來額外會做為少林門派給予技能的quest之一 因為剛好有兩個路線 所以可以限定所給予的fun
//如果打死和尚的玩家存在 且沒有紀錄挑水中的mark時 就給予紀錄使用方法一的mark
//  if ( !winner->query_temp("quests/bonze/water/method1") && !winner->query_temp("quests/bonze/water/method2") ) {//方法一 殺死和尚 方式既快速又省事 所以拉長重生時間為1小時 給予獎勵的npc為?? 並非本npc
//重複打死也沒關係 但是進行方法二的途中打死和尚 仍然算方法一 //將條件設嚴格點 必須先問過本npc 取得quest mark之後 打死才有效
  if ( !ob->query("quests/bonze/water/stop") && winner->query("quests/bonze/water/start") >1 ) { //限定只有第一位和尚被打死才有效 後半的判斷為只要接了任務後只要未領取方法二獎勵之前方可解方法一(同時會取消方法二的獎勵) //"last_damage_from" 不計玩家所在房間 即可找到該玩家並做後續判定
    winner->set_temp("quests/bonze/water/method1",1); //方法一 殺死和尚
    winner->set_temp("quests/bonze/water/method2",0); //打死和尚的同時取消方法二
    winner->set_temp("quests/bonze/water/times",0); //任務取消也是歸零
  }
  else { //已經有人打過和尚時 第二位之後攻擊的人不計方法一但仍然將挑水方式歸零 //限制解過方法二的玩家 仍需等待60分後才能解方法一(這部份為接任務的npc身上的quest判斷所導致) 避免同時解方法二與方法一的情況
    winner->set_temp("quests/bonze/water/method2",0); //打死和尚的同時取消方法二
    winner->set_temp("quests/bonze/water/times",0); //任務取消也是歸零
    winner->set_temp("quests/bonze/water/start",0); //既然任務取消了 同時取消接到任務的判定 由於本npc或其他二位之一已死亡 造成無法在某固定時間內重複接任務 //此mark歸零主要是避免無法再次接任務的困擾
  }
//  }
//不論怎麼死亡的 或是使用方法二後再打死npc時 都在房間紀錄並延長rb時間
  if( present("bucket",ob) ) //只要有人打死其中一位和尚時 構成人數不到三人 則觸發沒有糾紛=啟動npc挑水功能(? 就是關閉玩家解挑水quest的意思
  { //本判斷在作為傳遞mark的媒介 為了傳給另外兩人 因為本npc死掉就會在房間設定"no_reset"除非本npc亦設定會走動 這樣得改變設定=取消environment(ob) 因為走動後的環境並不等於重生的房間
    object obj = present("bucket",ob);
    obj->move(BONZE_ROOM"k08"); //第一隻npc(即本npc)重生的位置
    environment(obj)->set("no_reset",1);
    environment(obj)->set("quests/bonze/water/stop",1);
    environment(obj)->start();
    environment(obj)->add_temp("quests/bonze/water/ppl/method1/"+winner->query("id"),1); //紀錄玩家id 正常打死後 會在這目錄下紀錄id
    destruct(obj);

//npc有時候會不在 可以使用children()來判斷同時搭配上面的判斷式在重生的房間紀錄做下一步的判斷
//【眾神會議】小ｘ兒(whatup)說道: foreach(object ob in children("npc file name") { if(clonep(ob)) { 就是你要的哪隻線上亂走的npc} }
    foreach( object ob2 in children(BONZE_NPC"q1_trainee.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1); //有人打死其中一隻時 傳給其他兩隻(如果有出現時)使其關閉解quest的功能 但是已經在挑水的玩家 預計不妨礙其完成
        ob2->set("quests/bonze/water/time",time()); //紀錄時間 主要是給二廚 使其關閉解謎功能 暫定半小時
      }
    }
    foreach( object ob2 in children(BONZE_NPC"q1_trainee2.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
    foreach( object ob2 in children(BONZE_NPC"q1_trainee3.c") ) {
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
    foreach( object ob2 in children(FQ_NPC"k_monk3.c") ) { //在二廚身上紀錄
      if(clonep(ob2)) {
        ob2->set("quests/bonze/water/stop",1);
        ob2->set("quests/bonze/water/time",time());
      }
    }
  }
  ::die();
}
