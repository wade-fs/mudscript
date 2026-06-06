// 本程式由 wade 撰寫於 12/24/1995
// 需配合 bet 命令
#include "/open/open.h"
#include <ansi.h>
#include <login.h>

inherit ROOM ;
inherit CHINESE_D;

void init_data ();
string lucky_seven(object me);

int     rest;                   // 開始一局 rest=0, 局跟局中間休息 rest=1
int     bet;      // 開始下注
int     all_lose;

mapping  ctype = ([
  "money"  	:  "錢",
  "cash"   	:  "千兩銀票",
  "gin"    	:  "精",
  "kee"    	:  "氣",
  "sen"    	:  "神",
  "atman"  	:  "靈力",
  "force"  	:  "內力",
  "mana"  	:  "法力",
  "food"  	:  "食物",
  "water"  	:  "飲水",
  "bellicosity" :  "殺氣",
  "combat_exp" : "實戰經驗",
]);

void create() {

  seteuid(getuid()) ;

  set_temp ("channel_id", "賭博精靈");
  set ("short", "歇腳處");
  set ("long", @LONG

一張桌子, 幾張板凳, 蠻暗的一個小房間, 轎夫窩在這兒休息,
閒磕牙, 賭骰子, 有時候吵起來還會打架. 旁邊有一張紙寫著
賭博規則，你不妨看看紙(paper) 上面寫些什麼。
西邊跟東邊為狂想之麻將館(提供玩家休閒之用)!!
LONG);
  set ("light",1) ;
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tree2",
  "east" :__DIR__"mjroom1",
  "west" : __DIR__"mjroom2",
]));
  set ("light_up",1);
  set("item_desc", ([
       "paper": @LONG
如果想賭博，請打開賭博頻道，方法是直接輸入 gamble
如果不想聽賭博訊息，請關掉賭博頻道，方法是輸入 tune gamble

賭的方式是 bet <大/小/7> <多少> [種類]
其中 小 表示骰子出 1,2,3
     大 表示骰子出 4,5,6
     每次押東西的價值
     money 不可以超過1000 gold
     現在增加押門，賠率是一賠六
     可以押一到六點，每次押東西的數量不限
     7  表示骰子靠壁站的狀況，俗稱ㄎㄧㄚV 豆，這兒稱為
        Ｌｕｃｋｙ　Ｓｅｖｅｎ
其中的種類不給的話是金錢，可用的有:
        money           :       錢(預設選項)
        cash            :       千兩銀票(賭術二十以上)
        food,water      :       食物飲水(賭術十以上)
        atman,force,man :       靈力, 內力, 法力(賭術六十以上)
        potential       :       潛能(賭術八十以上)
限制條件如右: 完成一定數目的任務(目前設定成70%), 再加上
              賭技夠的話，可以賭錢以外的東西:
  賭技 <  10    --> 錢
  賭技 <  45    --> 食物，飲水
  賭技 <  60    --> 食物，飲水，內力，殺氣
　賭技 >= 60    --> 食物，飲水，靈力，內力，法力，殺氣

PS: 如果賭場沒開, 請在這兒下 "start" 命令
LONG
       ]) );

  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"goufu.c" : 1,
  CENTER_NPC"goufu1.c" : 3,
]));
  rest = 1;
  bet = 0;
  all_lose = 0;
  setup();
  call_out ("begin_game", 5) ;
}

void init()
{
  add_action ("do_start", "start");
  add_action ("do_stop", "stop");
}

int do_start()
{
  mixed  *callout;
  int  i, have;

  have = 0;
  all_lose = 0;
  callout = call_out_info();
  for (i=0; i<sizeof(callout); i++)
    if (callout[i][0] == this_object()) { have = 1; break; }
  if (!have) call_out ("begin_game", 5);
  else write ("人家賭的正高興, 你企圖重來會被圍毆喔!\n");
  return 1;
}

int do_stop()
{
  mixed  *callout;
  int  i, have;

  if (!wizardp(this_player())) return
    notify_fail ("人家正賭得爽歪歪的, 你企圖停止賭局會被圍毆喔!\n");
  have = 0;
  bet = 0;
  rest = 1;
  callout = call_out_info();
  for (i=0; i<sizeof(callout); i++)
    if (callout[i][0] == this_object()) { have = 1; break; }
  if (have) remove_call_out(callout[i][1]);
  return 1;
}

void begin_game ()
{
  int i;

  rest = 0;  // 開始一盤賭局
  bet = 0;
  all_lose = 0;

  init_data(); //清掉所有人的賭博記錄

  // 摸骰子
  call_out ("step1", 3+random(3));
}

void step1()
{
  if (random(2))
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家把一顆骰子拿出來給大家看，並且喊道: "
        "這是一顆公正骰子，請玩家鑑定一下!");
  else
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家把一顆骰子拿出來給大家看，並且喊道: 贏了笑哈哈, 輸了叫老爸!!");
  call_out ("step2", 3+random(3));
}

void step2()
{
  if (random(2))
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家看了看四周一眼，把骰子丟進搖蘆裡，並拿起搖蘆搖啊搖.....");
  else
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家把骰子丟進搖蘆裡，並拿起搖搖的咚囉咚響.....");
  call_out ("step3", 3+random(3));
}

void step3()
{
  if (random(2))
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家邊搖邊喊: 來來來，看看看，早來贏一半，慢來抱鴨蛋!");
  else
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家邊搖邊喊: 來來來，看看看，相打放一邊，博腳大過天!");
  call_out ("step4", 4+random(3));
}

// 停手，等開盅
void step4()
{
  if (random(2))
    CHANNEL_D->do_channel(this_object(), "gamble",
        HIY"莊家終於把搖蘆"HIY"放下來，向所有人大叫: "
        "有錢請下注，沒錢請回家抱老婆!"NOR);
  else
    CHANNEL_D->do_channel(this_object(), "gamble",
        HIY"莊家終於把搖蘆放下來，向所有人大叫: "
        "有錢的壓賭, 沒錢的看賭!!"NOR);
  bet = 1;
  // 開盅
  call_out ("step5", 20+random(5));
}

void step5()
{
  if (random(2))
    CHANNEL_D->do_channel(this_object(),"gamble",
        HIY"莊"HIY"家嘶聲力竭的喊道: 停"HIY"止下注, 要開牌了....。"NOR);
  else
    CHANNEL_D->do_channel(this_object(),"gamble",
        HIY"莊家嘶"HIY"聲力竭的喊"HIY"道: 停"HIY"止下注, 停止下注....。"NOR);
  bet = 0;
  call_out ("step6", 3+random(2));
}

int can_bet(object me, int value, string type)
{
  int v;
  object obj;

  if (type == "money") {
    if (me->can_afford(value)) me->pay_money(value);
    else return 0;
    return 1;
  }
  if (type == "cash") {
    v = me->query_skill ("gamble",1);
    obj = present ("cash",me);
    if (v < 20) return 0;
    if (!objectp(obj = present("cash",me))) return 0;
    if (value < 1) return 0;
    if (value >= obj->query_amount()) return 0;
    obj->add_amount (-value);
    return 1;
  }
  if ((v =me->query(type)) < value) return 0;
  v = me->query_skill ("gamble", 1);
  if ((type == "food" || type == "water") && (v < 30)) return 0;
  if ((type == "bellicosity") && (v < 50)) return 0;
  if ((type=="mana" || type=="atman") && (v < 60)) return 0;

  // chan { 修正讓非武者門派也能練內力.開放讓人可以在lv 45時就能賭內力
  if ((type == "force") && (v < 45)) return 0;
  if ((type=="potential") && (v < 70)) return 0;
  if(type == "potential" && ((me->query("potential") - me->query("learned_points")) - value) < 0) return 0;
  me->add(type, -value);

  return 1;
}


void pay_bet_2_player(object me, int money, string type)
{
  int  skill, attr, maxforce, maxatman, maxmana, con_factor, spi_factor;
  object mid;
  string file_name,amount;

  attr = me->query_cor() * me->query_int();
  maxforce = me->query("max_force");
  maxatman = me->query("max_atman");
  maxmana = me->query("max_mana");

  con_factor = me->query_con()/3;
  spi_factor = me->query_spi()/3;

  skill = (random(100-me->query_skill("gamble", 1))+1)*
    (me->query("bellicosity") +1)*
    attr;
  skill /= 150000;
  if (skill < 1) skill = random(attr/200)+1;
  me->improve_skill("gamble", skill);
  file_name="gamble/bet-"+type;
   amount=geteuid(me)+"gamble win "+sprintf("%d ",money)+type+" at "+ctime(time())+"\n";
  if(type=="force" && money > 5000)
    log_file(file_name,amount);
  if (type == "money")
    me->pay_player(money);
  if (type == "cash")        {
   mid=new("/obj/money/cash");
   mid->add_amount(money-1);
   mid->move(me);
   log_file(file_name,amount);
  }else me->add(type, money);

// wade 2002-12-13 人家想賭就賭，反正有輸有贏，不用想太多
#ifdef BET_LIMIT
  if (type == "force" && money > maxforce*con_factor+1) {
    tell_object(me,
            HIY"你承受不了莊家傳輸給你的內力而受了嚴重的內傷，內力盡失。\n"NOR);
    me->set("force",0);
    me->apply_condition("star-stial",15);
  }
  if(type=="atman" && money > maxatman*spi_factor+1)
  {
    tell_object(me,
            HIY"你承受不了莊家傳輸給你的靈力導至靈氣盡失。\n"NOR);
    me->set("atman",0);
  }
  if(type=="mana" && money > maxmana*spi_factor+1)
  {
    tell_object(me,
            HIY"你承受不了莊家傳輸給你的法力導至法力盡失。\n"NOR);  
     me->set("mana",0);
  }
#endif
}

void step6()
{
  object  *ob;
  int    i, num, point, money, flag;
  string  msg, type, point_msg, temp;


  num = random (1206);    //修改成可以押門by bss
                          //lucky 7的機率好像又更小了點
  if(num>=0 && num <200){
    num=1;
    point=1;
  }
  else if(num>=200 && num<400){
    num=1;
    point=2;
  }
  else if(num>=400 && num<600){
    num=1;
    point=3;
  }
  else if(num>=600 && num<800){
    num=2;
    point=4;
  }
  else if(num>=800 && num<1000){
    num=2;
    point=5;
  }
  else if(num>=1000 && num<1200){
    num=2;
    point=6;
  }
  else{
    num=0;
    point=7;
  }

  // 賭博禁止用 tintin, 但不明文規定, 用 {[(xx)]} 可以防止一部份
  if (num == 0) {
    msg = "7";
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家嘶聲力竭的喊道: ...開!\n"+
        HIY"莊"HIY"家啞著"HIY"嗓門的喊道:  哇! "
        HIY"Ｌｕｃ"HIY"ｋｙ　Ｓ"HIY"ｅｖｅｎ"NOR);
  }
  else if (num == 2) {
    msg = "大";
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家嘶聲力竭的喊道: ...開!\n"+
        "莊家啞著嗓門的喊道:  {[("+HIY+"大"+NOR+")]}");
    point_msg=CHINESE_D->chinese_number(point)+"點";
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家啞著嗓門的喊道:  {[("+HIY+point_msg+NOR+")]}");
  }
  else {
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家嘶聲力竭的喊道: ...開!\n"+
        "莊家啞著嗓門的喊道:  {[("+HIY+"小"+NOR+")]}");
    msg = "小";
    point_msg=CHINESE_D->chinese_number(point)+"點";
    CHANNEL_D->do_channel(this_object(), "gamble",
        "莊家啞著嗓門的喊道:  {[("+HIY+point_msg+NOR+")]}");
  }

  ob = users();
  if (num != 0) {
    for (i=0; i<sizeof(ob); i++) {
      flag=0;
      type = ob[i]->query_temp("gamble/type");
      if ((money=ob[i]->query_temp("gamble/"+point_msg)) > 0) {
         money=money*6;
         flag=1;
      }
      else if((money=ob[i]->query_temp("gamble/"+msg)) > 0) {
         money+=money;
         flag=1;
      }
      money = money  - (money / 2 * 10 /100 );
      if(money < 2) money = 2;
      if(flag){
        all_lose = 0;
        if (type == "money")
          tell_object (ob[i],
            "莊家賠你"+cvalue(money)+"。\n");
        else if(type == "cash")
          tell_object (ob[i],
            HIY"莊家賠你"+chinese_number(money)+"張"+ctype[type]+NOR"。\n");
        else
          tell_object (ob[i],
            HIY"莊家賠你"+chinese_number(money)+"點"+ctype[type]+NOR"。\n");

        // 理賠
        pay_bet_2_player(ob[i], money, type);
      }
      else if (ob[i]->query_temp("gamble")) {
        ob[i]->improve_skill("gamble", 1);
        tell_object (ob[i],
          "莊家笑笑對你說: Sorry lah....歡迎下次再來比過。\n");
      }
    }
  }
  else {
    msg = "";
    for (i=0; i<sizeof(ob); i++)
      if (ob[i]->query_temp("gamble/7") > 0) {
        all_lose = 0;
        msg += HIY+lucky_seven(ob[i])+NOR;
      }
    CHANNEL_D->do_channel(this_object(), "gamble", HIY+msg+NOR);
  }

  if (all_lose)
    if (random(2))
      CHANNEL_D->do_channel(this_object(), "gamble",
         HIR" 通　～～～～～～～～～　殺 "NOR);
    else
      CHANNEL_D->do_channel(this_object(), "gamble",
        HIR"莊家露出詭異的笑容說道: 願賭服輸....謝謝各位大爺捧場...."NOR);
  rest = 1;

//modify by rong 85.4.5
  init_data(); //清掉所有人的賭博記錄
  call_out ("begin_game", 15+random(5));
}

// 啟始資料設定, 清掉所有人的賭博記錄
void init_data()
{
  object        me, *ob;
  int           i, j;

  ob = users();
  for (i=0; i<sizeof(ob); i++)
    ob[i]->delete_temp("gamble");
}

int query_bet()
{
  return bet;
}

int player_bet(object me, string num, int value, string type)
{
  int point;
  if (value <= 0) tell_object(me, "你你你壓這是什麼值啊, 耍人啊。\n");
  else if (bet == 0) {
    tell_object(me, "賭局還沒開始哩。\n");
  }
  else if (num != "大"  && num != "小" && num != "7"
         && num!="1" && num !="2" && num!="3" && num!="4"
         && num!="5" && num!="6")
    tell_object(me, "只能壓 '大', '小',一點到六點或 '7'\n");
  else if (num != "7") {
      if (can_bet(me, value, type)) {
        if (type == "money" && value > 10000000) {
          tell_object(me, "你壓的賭資太大了, 為防止您傾家當產, 請壓少一點!\n");
          me->pay_player(value);
          return 1;
        }
        // 已經不賭 exp 了, 不過留著也沒差...
        else if (type == "combat_exp" && value > 100000) {
          tell_object(me, "你壓的經驗太大了, 為防止您一下子變肉腳, 請壓少一點!\n");
          me->add("combat_exp", value);
          return 1;
        }
        all_lose = 1;
        me->set_temp("gamble/type", type);
        if(num=="大" || num=="小" || num=="7")
          me->add_temp("gamble/"+num, value);
        else{
          sscanf(num,"%d",point);
          me->add_temp("gamble/"+CHINESE_D->chinese_number(point)+"點",value);
        }
        if (type == "money")
          tell_object(me, "你付"+cvalue(value)+"給賭場。\n");
        else if(type == "cash")
         tell_object(me, "你付"+chinese_number(value)+"張"+ctype[type]+"給賭場。\n");
        else
         tell_object(me, "你付"+chinese_number(value)+ctype[type]+"給賭場。\n");
      }
      else
        tell_object(me, "你掏了掏口袋, 慘了, 不知道是不是身上"+ctype[type]+"不夠?\n"+
                        "還是瞧不起我的賭術？賭場竟然不讓我賭！");
  }
  else {
    if (me->query("combat_exp") < 200)
        tell_object(me, "你的實戰經驗不足, 請多點經驗之後再來賭博!\n");
    else if (me->query("potential")-me->query("learned_points") >= value) {
      all_lose = 1;
      me->set_temp("gamble/type", type);
      me->add("potential", -value);
      me->add_temp("gamble/7",value);
      tell_object(me, "你用"+chinese_number(value)+"點潛能當賭注。\n");
    }
    else
      tell_object(me, "去跟師父多學學再來賭博吧。\n");
  }
  return 1;
}

string lucky_seven(object me)
{
  int    point, earn, lp, pp;

  lp = me->query("learned_points");
  point = me->query("potential");
  earn = 10 * me->query_temp("gamble/7");
  //原本是四十倍.現在改成三倍
  pp = point+earn-lp;
  if (pp > 100000) pp = 100000;

  me->set("potential", pp+lp);

  log_file("lucky_seven", sprintf ("%s(%s)在%s中了 7, 潛能從 %d 到 %d.\n",
        me->query("name"), me->query("id"), ctime(time()), point-lp, pp));

  return "莊家大聲叫道: 恭喜!!!"+me->short()+"\n";
}
