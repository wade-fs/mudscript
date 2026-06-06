// 增加少林廚藝學院的quest相關 2010/09/06 by blazakira

#include <ansi.h>
inherit NPC;

string ask1();	// 命名
string ask2();  // 寶物
string ask_pepper();

void create()
{
  seteuid(getuid());
  set_name( "你爸爸", ({ "papa" }) );
  set("long", @LONG
你正盯著自己的爸爸看著, 看他滿懷心事的樣子, 整天憂愁苦臉的,
不知是為了哪一樁事情在擔憂, 做兒子的您是不是能夠幫幫他呢?
LONG);
  set("gender", "男性" );
  set("race", "人類");
  set("age",55);

  set("inquiry", ([
      "冒險"	: "要不是我這把老骨頭不中用了, 你爸爸我自己去好了, 省得你囉唆!",
      "祖宗十八代":"小子囉哩巴唆的, 問你祖宗十八代幹嘛?!懷疑是我兒子啊!",
      "埋葬"	: "東村口外的小山丘上的那堆亂墳不就是了嗎?",
      "種田"	: "種田有什麼用, 要是找到寶物就好了.",
      "耕種"	: "耕種有什麼用, 要是找到寶物就好了.",
      "武功"	: "聽說蜀山附近躲著怪獸, 又聽說那邊住著劍仙, 不知是真是假.",
      "蜀山"	: "你也知道你老爸一生都在凌雲村, 希望你能出去幫我找一找蜀山在哪.",
//      "寶物"    : (: ask2 :), //不清楚是什麼樣的quest 暫時取消本訊息　by blazakira 2010/09/18
      "寶物"    : "寶物呀－－(遠目",
      "媽媽"	: "唉, 要不是你媽去的早, 我也不必依靠你照顧了.",
      "心事"	: (: ask1 :),
      "憂愁苦臉": (: ask1 :),
      "擔憂"	: (: ask1 :),
      "妹妹"	: (: ask1 :),
      "張大嬸"  : "她外號張快嘴, 她的話也能信嗎?",
      "張快嘴"  : "還不是因為她有話包不住嘴, 逢人便到處宣傳別人的密秘?!",
      "陌生人"	: "你豬啊你, 就因為是陌生人, 又有誰會知道了啊!",
      "辣椒"	: (: ask_pepper :),
      "調味料"	: (: ask_pepper :),
  ]) );

  setup();
}

string ask1()
{
  object	me=this_player();

  if (me->query("quests/chfn"))
    if (random(2))
	return "你爸爸氣呼呼的大叫: 叫你出去找冒險學武, 你跑來跟我囉唆, 欠扁嗎?!\n";
    else
	return "你爸爸紅著臉叫道: 來人啊, 看看我這不肖子, 有事沒事跑回來跟我囉唆!\n";

  if (!me->query_temp("quests/chfn")) me->set_temp("quests/chfn",1);
  switch (random(5)) {
    case 0:
	return "你媽媽老來生了個掌上明珠, 可惜前天傍晚之後\n"
	"就沒再看到人了, 你說會不會急死人!";
	break;
    case 1:
	return "唉...........";
	break;
    case 2:
	return "你有看到你妹妹嗎?\n";
	break;
    default :
	return "聽張大嬸說, 有人看到陌生人在附近走動, 不知是不是被拐走了.";
	break;
  }
}

int chat()
{
}

string short()
{
  object	me=this_player();

  return sprintf ("%s的爸爸(%s' papa)", me->name(), me->query("id"));
}

int accept_fight(object who)
{
  say ("你....你這不肖子, 你老爸這把骨頭你也想跟我動手動腳....\n");
}

int accept_kill(object who)
{
  say ("你....你這不肖子, 連你老爸你都想砍....\n");
}

string ask_pepper()
{
        object me = this_player(),ob;
		if(!me->query_temp("quests/bonze/food/start")) return "你在問什麼我怎麼聽不懂。"; //食材任務判斷失敗時
		if (!me->query_temp("quests/bonze/food/pepper")) //未領家傳辣椒醬時
		{
			command("say 你這小子想家了吧。");
            command("say 這罐讓你帶著吃，有空記得常回來看我啊。");
			message_vision("$N看著父親剛剛遞過來的家傳辣椒醬，回想起過去一家和樂融融的點點滴滴。\n",me);
//＊道具位置待改變
			ob=new("/open/bonze/food_quest/pepper");
			ob->set_temp("quests/bonze/food",1); //為使道具不可離線=限制玩家無限儲存道具在倉庫(離線角色)的作法
			ob->move(me);
			me->set_temp("quests/bonze/food/pepper",1); //限制玩家此階段只能領取一次
		}
		else
		{
			command("say 怎麼樣，那罐夠辣吧，就跟你母親做得味道一樣吧。");
			command("sad");
		}
		return"";
}
