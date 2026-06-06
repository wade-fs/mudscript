// rewrite from washboy.c
// harlot.c by powell
// add quest 壞人證明 & 拯救水仙 by wade

#include "/open/open.h"
inherit NPC;

string do_ask1();
string do_ask2();

void create()
{
        set_name("妓女", ({ "Harlot", "harlot" }) );
        set("race", "人類");
        set("gender", "女性");
        set("age", 18);
        set("long", "她臉上途了厚厚一層胭脂, 正忙著物色有錢的大爺。\n");
        set("attitude", "peaceful");
        set("str", 17);
        set("cor", 15);
        set("combat_exp",318);
        set("chat_chance", 5);
        set("chat_msg",({

             "妓女微笑道︰人客裏面坐喔.....\n",
             "妓女擠眉弄眼的對你說道 : 大爺 ! 想不想舒服舒服呀。\n",
             "妓女喃喃自語的道 : 水仙姑娘不見後, 麗春院的生意少了不少..\n",
             "妓女偷偷的告訴你 : 你想知道水仙姑娘的下落嗎? \n",
             "妓女靠到你身邊說道 : 大爺想到樓上休息嗎?\n",
             "妓女笑道 : 大爺如果對我有興趣, 可以先找老鴇接洽接洽喔.\n",

        }));
        set("inquiry", ([
            "移花宮"            :       "噓，不要命了嗎? 這種事也問得的? 快閉嘴。",
            "老鴇"              :       "老鴇真沒人性，連小女還都不放過。",
            "惡人谷"            :       "那是惡人聚集的地方，您問我也沒用，去問問壞人吧。",
            "麗春院"            :       "您不知道嗎? 麗春院老闆是鼎鼎大名的韋小寶。",
            "老鴇"              :       "老鴇要我在這兒好好招呼客人, 客倌您就選我嘛!",
            "水仙姑娘"          :       (: do_ask1 :),
            "哥兒們"            :       (: do_ask2 :),
            "英俊的哥兒們"      :       (: do_ask2 :),
        ]) );
        set_temp("apply/attack", 10);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 2);

        setup();
       carry_object(CENTER_OBJ"cloth2")->wear();
       carry_object(CENTER_OBJ"pant1")->wear();
}

// 問水仙當起頭
string do_ask1()
{
  object me=this_player();

  if (me->query("quests/help_water_god")) {
    me->delete_temp("quests/help_water_god");
    if (random(2))
      return "對了，老鴇要我謝謝你幫忙救出水仙姑娘。";
    else
      return "您也要關心關心妹子嘛，老是問水仙水仙的。";
  }
  else if (me->query_temp("quests/help_water_god"))
    switch (random(5)) {
      case 0:
        return "哎呦，我已經把所有知道的都說了呀。";
        break;
      case 1:
        return "這件事開頭就是因為那個英俊的小子嘛。";
        break;
      case 2:
        return "其實要不是水仙姑娘先接待那位小哥，我也會愛上他的。";
        break;
      case 3:
        return "聽說水仙與那英俊的小哥在這麗春院風流了三天三夜，真羨煞人了。";
        break;
      default:
        return "一問再問，您煩不煩啊。";
    }
  else {
    me->set_temp("quests/help_water_god", 1);
    return ("不瞞您說，上次有個英俊的哥兒們來，" +
        "咱水仙姑娘就失魂落魄的了。\n"+
        "妓女接著說道: 這次要不是水仙姑娘肚子越來越大，終於"+
        "被移花宮的人發現了，他們也不用逃亡了。");
  }
}

string do_ask2()
{
  object me=this_player();
  int   query;

  query = me->query_temp("quests/help_water_god");
  if (!query || me->query("quests/help_water_god"))
  {
    if (random(2))
      return "那英俊的哥ㄦ們關我們啥事啊，快跟我進房間去快活快活。";
    else
      return "您愛說笑了，這兒不就有一位英俊的哥ㄦ們嗎?";
  }
  switch (random(7)) {
        case 0:
          return "那位老兄跟水仙姑娘現在正在被追殺，請您趕快去解救吧。";
          break;
        case 1:
          return "哎呀呀，救人如救火，這事我們小女子無法出面，全靠您了。";
          break;
        case 2:
          return "那位老兄搞大了水仙姑娘的肚皮，兩人就私奔去了。";
          break;
        case 3:
          return "聽說水仙姑娘本來是繡玉谷移花宮大宮主的婢女。"+
               "妓女說道﹕至於那位老兄就莫宰羊了。";
          break;
        case 4:
          return "這哥兒們有一位江湖上的好朋友，叫什麼來的? 一時忘記了。";
          break;
        case 5:
          return "想救水仙姑娘的話，您還是趕快上路吧。";
          break;
        default:
          return "一問再問，您煩不煩啊。";
  }
}
