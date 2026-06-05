#include <ansi.h>

inherit ROOM;
string show_word(object me);

string *great = ({
               "        故事妖精開講囉....  " + NOR, 
            HIY + "    最後之夢幻傳說開始~~~~~ " + NOR,
            HIW + " 漂漂筱嵐美眉有天走路走到犛田..." + NOR,
            HIW + " 因為太懶了,不想起來, 但是感覺到有種異樣眼光看著她" + NOR,
            HIW + " dean的邪惡眼神不斷著看著她, 口水都快流出來了..:D~~" + NOR,
            HIW + " dean大喊 : 我要劫色 !! 給我脫~~~~~~" + NOR,
            HIW + " Anmy 以純潔的眼神看著小恩恩, 想了好久好久.... " + NOR,
            HIW + " dean惡狠狠的瞪著她, 似乎像大野狼般一口吃下嵐嵐.. " + NOR,
            HIW + " 此時民族..的救星 不~Mud的奇才Lum登場...." + NOR,
            HIC + "     光 芒 四 射    閃 閃 動 人       " + NOR,
            HIW + " 小拉姆看著小恩恩, 二人似乎一觸待發, 一旦動手.." + NOR,
            HIW + " 將勢必是 一時勾動天雷地火 一發不可收拾 !!! " + NOR,
            HIG + "                 可是... " + NOR,
            HIW + " 邪惡小恩不停地看著小拉姆上下很多次, 好似想著什麼.." + NOR,
            HIW + "                          to be continue... " + NOR,
});

void create ()
{
  set ("short", "[1;35m過去時空[0m 葬劍亭");
  set ("long", @LONG

你現在來到一個山腰靠近山頂的亭子﹐亭子前立著一個兩丈多高的
石碑(monolith)﹐從亭子裡遠眺北方連綿不盡的大山﹐使你不禁感到胸
臆之間一股英雄情懷油然而生﹐葬劍亭據說每到夏日夜晚﹐野風吹過﹐
會產生一陣陣嗚嗚的哭泣聲﹐這也是水煙十景中的「孤亭劍泣」。出了
亭子﹐往南便是直通虹台的石階。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path2",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "word" : " 在你眼前似乎有人以渾厚的內力將一些刻字
以沙覆蓋過去 , 想要看清楚 , 可能得花點氣力 ..
",
  "monolith" : "石碑上龍飛鳳武地刻著幾個大字﹕

    風波劍神黎紅藥前輩葬劍於此﹐水煙閣第四代七長老比武
    不勝﹐以奸計害人而自取其辱﹐武者皆不齒其小人行徑﹐
    合力擊殺於此﹐甲辰年立此亭書銘其事以為後人殷鑑。
                        第三代水煙閣主 於蘭玫音
                        第四代水煙閣主 聶    言   合立
                        第五代水煙閣主 段 柏 山

     你隱隱的看到石碑的右後處似乎模糊地寫了幾個字 ...
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/executioner" : 1,
]));

  setup();
}
void init()
{
   add_action("start_great","show");
}
int start_great()
{
  call_out("show_great",1,this_player(),0);
  return 1;
}
int show_great(object me,int x)
{
   int i;
   string msg;
   msg = great[x];
   message_vision(msg+"\n",me);
   if( ++x < sizeof(great) ) {
             call_out("show_great", 1 ,me,x);
    }
}
