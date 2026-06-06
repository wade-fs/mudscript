#include "/open/open.h"
inherit NPC;

void create()
{
        set_name("軒轅三光", ({ "san guan", "guan" }) );
        set("race", "人類");
        set("gender", "男性");
        set("age", 38);
        set("long", @LONG
他是惡賭徒軒轅三光，每次一賭下去，不輸光當光褲子脫光是不會
罷手的。他賭術奇差，卻老是自命不凡，唯一值得自傲的，就是他只要
一賭下去，非得對方認輸不可，這也是惡賭徒稱號的由來。不過他有一
項優點，從不賴賬。
LONG);
        set("attitude", "peaceful");
        set("str", 27);
        set("cor", 25);
	set("combat_exp", 1689);
        set("chat_chance", 8);
        set("chat_msg",({  
		"軒轅三光說道: 終於讓我找到一本賭林奇書了。\n",
		"軒轅三光說道: 誰敢賴賬我一定Ｋ死他。\n",
		"軒轅三光說道: 賭博最重要的是輸贏各憑本事，輸要輸得起。\n",
		"軒轅三光說道: 多年來我已經沒碰到敵手了。\n",
        }));
        set("inquiry", ([
	"賭神秘術"	: "你以為問我我會給你嗎? 別傻了, 除非跟我賭一局！",
	"輸得起"	: "廢話, 不然還有誰願意跟你賭啊!",
	"賭林奇書"	: "我找了老半天才找到的，當然是珍而密之囉。",
	"本事"		: "哈，來來來，賭一場見真章。",
	"輸贏各憑本事"	: "小子，難不成你不懂賭博規矩？還想賴賬？",
	"賴賬"		: "誰誰誰? 誰敢賴賬我去Ｋ死他!",
	"敵手"		: "小子, 想比一場嗎? 來來來, 回答我! 要不要比一場?",
	"賭博"		: "賭博是我最拿手的了，你願意跟我比一場嗎？快點回答！",
	"比一場"	: "比一場? 只要回答 yes or no 就可以了。",
	"回答"		: "就是 answer y 或者 answer n 嘛!",
        ]) );
        set_temp("apply/attack", 20);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 4);
	set_skill("dodge",30);
	set_skill("parry",40);
 
        setup();
}

void init()
{
  add_action("do_answer", "answer");
}

int do_answer(string arg)
{
  object	me=this_player();
  int		value;

  printf ("%O\n", arg);
  if (arg == "n" || arg == "no" ) return
	notify_fail ("軒轅三光說道: 不要就算了, 還囉哩囉唆的。\n");
  else if (arg == "y" || arg == "yes") {
    say ("這裡有一個銅板, 你猜是正面還是反面?\n");
    return 1;
  }

  if (arg == "你賴賬" || arg == "賴賬") {
    if (me->query_temp("quests/gamble_book") == 2) {
	message_vision("軒轅三光說道: $N敢說我賴賬, 不服氣來打一場架啊。"
		"還是乖乖再賭一局試試吧?!要不要再來一盤?",
		me);
	return 1;
    }
    else {
	message_vision("軒轅三光說道: 賴賬? 賭博的規矩你是會不會啊!"
		"多說無用, 不跟你玩了, 哼!\n",
		me);
	return 1;
    }
  }
  value = random(2);
  if (arg == "正面" || arg == "正")
    if (value) {
	if (me->query_temp("quests/gamble_book"))
	  me->set_temp("quests/gamble_book",2);
	message_vision("軒轅三光說道: 哈! 不是反面, $N猜正面就錯了!\n", me);
    }
    else say ("哈! 是反面, 你猜正面就錯了!\n");
  else if (arg == "反面" || arg == "反")
    if (value) say ("哈! 是正面, 你猜反面就錯了!\n");
    else {
	if (me->query_temp("quests/gamble_book"))
	  me->set_temp("quests/gamble_book",2);
	say ("哈! 不是正面, 你猜反面就錯了!\n");
    }
  else {
    message_vision("軒轅三光說道: 有什麼問題直接說就好了, 不必那麼客氣 :)\n",
	me);
    return 1;
  }
  say ("怎樣, 願賭服輸, 不得賴賬, 要不要再來一盤?\n");
  return 1; 
}

void die()
{
  object        me;

  me = this_object()->query_temp("last_damage_from");
  if (me) {
    if (me->query_temp("quests/gamble_book") >= 2) {
      message_vision("軒轅三光說道: 好吧, 我認了, 跟你說吧, 為了怕人搶, 我把"
	"賭神之秘藏在這裡的某個地方，有本是你自己找出來。\n",
	me);
      me->set_temp("quests/gamble_book", 3);
    }
  }

  ::die();
}
