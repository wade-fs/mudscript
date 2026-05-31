inherit F_FUNCTION;
inherit SSERVER;
#include <ansi.h>

int perform (object me, object  weapon)
{
  object ob,*enemy;
  object weaponn;
  int i,j,k;
  int funlv = me->query("functions/dog-phoenix/level");
  int fun = me->query("functions/holy-phoenix/level");
  int corr = me->query_cor(1);
  enemy = me->query_enemy(environment(me));
  i = sizeof(enemy);
  j = random(i);

  if (!me->is_fighting() )
     return notify_fail("浴火鳳凰只能在戰鬥中呼叫出來！\n");
  if (!(this_player()->query("beggar/got_phoenix")))
     return notify_fail("你能力還不足以發揮此威力\n");
  if (funlv < 100)
     return notify_fail("你的技巧不足，叫不出仙鳳哦！\n");
  if (me->query("class")!="beggar")
     return notify_fail("不是丐幫之人是無法領會的！\n");
  if (corr < 20)
     return notify_fail("你太膽小了，連仙鳳也不屑出來幫你了。\n");
  if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff")
     return notify_fail("你沒拿武器哦！\n");
  message_vision("\n\n
                          "HIR"▁▃"NOR"
                    "HIR"▂▅▇"NOR""RED""BBLK"▄▁▃"NOR"
                       "BLK""BRED"▆▄ "RED""BBLK"◣  "HIR"▄▆"NOR""RED""BBLK"▆▅▅▄▃▂▁"NOR"
                            "RED"◥◣ "HIR"◥"BRED"▉≡ ==—￣ "BLK""BRED"▁ "NOR""RED""BBLK"▆▄▂"NOR"
                  "HIR"▁▂"NOR"       "RED"◥"BRED" "BBLK"◣"HBRED"▉═￣     "NOR""BLK""BRED"▁▄"NOR"
               "HIR"◢"BRED"◤◥"BBLK"█▆▅▆▇"BRED"▆  ＼   "NOR""RED""BBLK"▇"BLK""BRED"▄"NOR"
               "HIR""BRED"▍     ◥◥◥ ◥◥▊  "NOR""RED""BBLK"◣"NOR"
               "HIR""BRED"▎   ﹨  ◥◥ ＼＼ ＼    "NOR""BLK""BRED"▃"NOR"
               "HIR""BRED"▏｜  ﹨   ＼ ＼ "NOR""BLK""BRED"▄"NOR" "BLK""BRED"▆▃     "RED""BBLK"▃▂▃▁"NOR,me);
  message_vision("
               "HIR""BRED"▏∥         "NOR""BLK""BRED"▄"NOR"            "BLK""BRED"▇"RED""BBLK"◥▄  ▂"BLK""BRED"▇▅"RED""BBLK"▄"NOR"
               "HIR""BRED"   │     "NOR""RED""BBLK"◥"NOR"                     "BLK""BRED"▅"RED""BBLK"▃"BLK""BRED"▅"RED""BBLK"▃  "BLK""BRED"▅"RED""BBLK"▃"NOR"
               "HIR""BRED"   ║   "NOR""RED""BBLK"▊▏                         "BLK""BRED"▄"RED""BBLK"◣ "BLK""BRED"▅"RED""BBLK"▃ ◥▃"NOR"
                "BRED"       "RED""BBLK"▎                              ◥    ◥▃ ◥▃"NOR"
                "BRED"     "RED""BBLK"▉▏                                ▍     ▌   ◥"NOR"
                "BLK""BRED"▎  "RED""BBLK"▊▎"NOR"                                  "RED"▍     ◥"NOR"
                  "BRED"    "RED""BBLK"∥                                  ▎       ▍"NOR"
                   "BLK""BRED" ∣"NOR"                                    "RED"▍        ▍"NOR"
                    "RED"◥                                   ▍          ▎"NOR"
                                                   "RED"▁▂◤             ▏"NOR"
                                                                    "RED" ▏\n\n"NOR,me);
  message_vision(HIY"$N呼喚出耀眼的浴火鳳凰，天際剎時血紅，滾燙的火球圍繞周圍，只見．．．\n\n"NOR,me);
  {
   switch(random(3))
   {
    case 0:
           message_vision(HIW"\n聖獸鳳凰化為點點靈氣，包圍在$N身旁，為$N治療大半傷勢。\n"NOR,me);
           me->receive_heal("kee",fun*15/2);
           me->receive_curing("kee",fun*15/2);
           me->receive_heal("gin",fun*15/4);
           me->receive_curing("gin",fun*15/4);
           me->receive_heal("sen",fun*15/4);
           me->receive_curing("sen",fun*15/4);
           me->add("force",-250);
           COMBAT_D->report_status(me);
           me->start_busy(2);
           break;
    case 1:
           if (random(9) < 6)
           {
            message_vision(HIY"聖獸揮動巨翅，數以萬計的焰柱將$N圍住，動彈不得。\n"NOR,enemy[j]);
            while(i--)
            {
             if (fun <30) fun = 1;
             if (30 < fun < 70) fun=2;
             if (fun>70) fun =3;
             enemy[i]->start_busy(random(2)+random(fun));
             enemy[i]->apply_condition("fire",3);
             COMBAT_D->report_status(enemy[i]);
            }
           }
           else
           {
            message_vision(HIY"$N所呼叫出來的聖獸，巨翅突然不見了，只好拼命揮動不像話的雞爪示威。\n"NOR,me);
            message_vision(HIG"$n見狀頓時笑倒在地，不理會$N的攻擊！\n\n"NOR,me,enemy[j]);
           }
           me->add("force",-250);
           me->start_busy(random(3));
           break;
    case 2:
           if (random(me->query_per()) > 15)
           {
            for(k=0;k<i;k++)
            {
             message_vision(HIW"$N全身被浴火鳳凰穿刺而過，全身被暴火包住，哀號聲不斷！\n"NOR,enemy[k]);
             //printf("\n你現在Holy-phoenix的等級為 %o !!\n",fun)
             enemy[k]->receive_wound("kee",fun*20);
             enemy[k]->receive_wound("gin",fun*5);
             enemy[k]->receive_wound("sen",fun*5);
             COMBAT_D->report_status(enemy[k]);
            }
           }
           else
           {
            message_vision(HIR"$n機靈地閃過了仙鳳致命的攻擊，仍心有餘悸。\n"NOR,me,enemy[k]);
           }
           me->add("force",-250);
           me->start_busy(random(3));
           break;
   }
   message_vision(HIW"$N使出火鳳過度，一時虛力，四肢不聽使喚。\n"NOR,me);
   me->add("water",-25);
  }
  if (fun <100)
     function_improved("holy-phoenix", random(200)+fun);
     return 1;
}


