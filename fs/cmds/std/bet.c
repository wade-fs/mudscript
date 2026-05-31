#define GAMBLE_ROOM "/open/center/room/men"

inherit F_CLEAN_UP;

string  *bet_type = ({
        "cash",		// 銀票
        "money",	// 金幣
        "food",		// 食物
        "water",	// 水
        "combat_exp",	// 戰鬥經驗值
        "force",	// 內力
        "mana",		// 法力
        "atman",	// 靈力
	"potential", 	// 潛能
	"bellicosity",  // 殺氣
});

int main(object me, string arg)
{
        int     value, n;
        string  num, bet, type;
        mapping quests, my_q;

        seteuid(getuid(me));

        if (!arg)
          return notify_fail ("請用 help bet 查壓錢的方法。\n");
        else if (sscanf (arg, "%s %s", num, bet) != 2)
          return notify_fail ("請用 help bet 查壓錢的方法。\n");
        type = "money";
        if (sscanf (bet, "%s %s", bet, type) == 2)
          // 不是錢一定是完成夠多的任務才有資格
          if (type != "money" && type != "cash") {
            quests = "/cmds/std/quests"->query_quests();
            my_q = me->query("quests");
            if (sizeof(my_q)*10 < sizeof(quests) * 7)
              return notify_fail ("你沒有資格自由選定賭注型態, 請多完成幾個任務後再來。\n");
          }
        if (member_array(type, bet_type) != -1 &&
            !catch(load_object(GAMBLE_ROOM)))
        {
          /* 取消殺氣限制 by whatup
if(type=="bellicosity" && (me->query("family/family_name")=="魔刀門" ||
me->query("family/family_name")=="魔刀莫測") &&
me->query("bellicosity") > me->query("max_force"))
 return notify_fail ("你殺氣大於您的最大內力，夠用了不能再賭。\n");
 */
if(type=="atman"&&me->query("class")!="dancer" && me->query("atman")>100000)
return notify_fail ("你靈力大於100000夠用了不能再賭。\n");
if(type=="atman"&&me->query("class")=="dancer" && me->query("atman")>150000)
return notify_fail ("你靈力大於150000夠用了不能再賭。\n");
          if (me->query_temp("gamble")) return notify_fail("你已經壓好離手了。\n");
          if (sscanf (bet, "%d", value) != 1 || value < 0) return
                notify_fail ("賭注一定要正數, 請用 help bet 查壓錢的方法。\n");
        if(type == "cash" && value < 300)
          return notify_fail ("本賭場只接收三百張以上的千兩銀票的賭注,小賭注一律不接收!!\n");
        if(type == "cash" && (num=="大" || num=="小"))
          return notify_fail("本賭場不接受銀票賭大小，要賭就賭點數!!!\n");

          return GAMBLE_ROOM->player_bet(me, num, value, type);
        }
        else return notify_fail("不是賭注型態不對, 就是賭場出問題.\n");
}

int help(object me)
{
        me->start_more(@HELP
指令格式 : bet <大/小/點數/7> <多少> [種類]
指令說明 :
           這個指令可以讓你壓賭，對於賭徒來說，是一項又方便又
         有趣的玩意兒。如果想賭博，請打開賭博頻道，方法是直接
         輸入 gamble。 如果不想聽賭博訊息，請關掉賭博頻道，方
         法是輸入 tune gamble。

其中 小 表示骰子出 1，2，3
     大 表示骰子出 4，5，6
     賭大小有限制都是以1000000為上限, 但是cash不能賭大小
     新增加押點數, 一到六點, 賠率是一賠六, 可以用cash賭, 不過一次最少要300 cash
     7  表示骰子靠壁站的狀況，俗稱ㄎㄧㄚV 豆，這兒稱為
        Ｌｕｃｋｙ　Ｓｅｖｅｎ
其中的種類不給的話是金錢，可用的有:
        money             :       錢(預設選項)
        cash              :       千兩銀票(賭術二十以上)
        food，water       :       食物飲水(賭術十以上)
        force             :       內力(賭術四十五以上)
        bellicosity       :       殺氣(賭術在五十以上)
        atman，man        :       靈力，法力(賭術六十以上)
        potential         :       潛能(賭術八十以上)
限制條件如右: 完成一定數目的任務(總任務數的 70% (含)以上)，再加上
              賭技夠的話，可以賭錢以外的東西:
  賭技 <  10    --> 錢
  賭技 <  45    --> 食物，飲水
  賭技 >  50    --> 殺氣，內力，食物，飲水
  賭技 >  60    --> 食物，飲水，靈力，內力，法力

PS: 如果賭場沒開，請去賭場下 "start" 命令
PS: 錢以外的特殊種類必須要有完成任務總數的七成才行，
    此外，還需要一定的賭技
PS: 最多下 1000000，還是 money 都是如此
PS: 賭cash的話沒有限制下的數量
HELP
    );
    return 1;
}
