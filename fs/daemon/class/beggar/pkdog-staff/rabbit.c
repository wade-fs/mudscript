inherit F_FUNCTION;
inherit SSERVER;
#include <ansi.h>

int perform (object me, object  weapon)
{
        object ob,*enemy;
        object weaponn;
        int i,j,k;
        int funlv = me->query("functions/dog-phoenix/level");
        int corr = me->query_cor(1);
        enemy = me->query_enemy(environment(me));
        i = sizeof(enemy);
        j = random(i);
        if (!me->is_fighting() )
           return notify_fail("浴火鳳凰只能在戰鬥中呼叫出來！\n");
        if (!wizardp(this_player()))
            return notify_fail("你不是巫師，不能使用此招式。\n");
        if (funlv < 100)
           return notify_fail("你的技巧不足，叫不出仙鳳哦！\n");
        if (me->query("class")!="beggar")
           return notify_fail("不是丐幫之人是無法領會的！\n");
        if (corr < 20)
           return notify_fail("你太膽小了，連仙鳳也不屑出來幫你了。\n");
        if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff")
           return notify_fail("你沒拿武器哦！\n");
          message_vision("\n\n

        " + BBLU + "     " + BLU + "" + BBLK + "◤ " + BLK + "" + BRED + "◤                " + NOR + "
        " + BLK + "" + BBLU + "▁▅" + BRED + "◤    ▂▄▅" + NOR + "▁▁▁" + BLK + "" + BRED + "▄▂" + NOR + "
         " + RED + "◢" + BLK + "" + BRED + "◢" + NOR + "▁" + BLK + "" + BRED + "▄" + BBLK + " " + NOR + "◢▇" + BLK + "" + BWHT + "        " + NOR + "▇▅" + NOR + "
        " + RED + "◤" + BLK + "" + BWHT + "◤   " + NOR + "▇" + BLK + "" + BWHT + "                 " + NOR + "
        ◢" + BLK + "" + BWHT + "        ▁▁            " + NOR + "
        " + BLK + "" + BWHT + "     " + NOR + "◤▁▃▄▃▂" + BLK + "" + BWHT + "▆▅▄▂ " + NOR + "
        ◢" + BLK + "" + BWHT + "◢" + NOR + "▃" + BWHT + "                " + NOR + "▆▄" + NOR + "
        " + BLK + "" + BWHT + "▕▍                      " + NOR + "
        " + BLU + "▄" + BLK + "" + BWHT + "▏▁▁                " + HIW + "  " + NOR + "
        " + BLK + "" + BBLU + " " + BLU + "" + BBLK + "▍" + NOR + "▄▅▅" + BLK + "" + BWHT + "    " + NOR + "▃" + BLK + "" + BWHT + "▅▄       " + NOR + "
        " + BLU + "▊" + BLK + "" + BWHT + "▏     ▂       " + NOR + "▄▂◥" + BWHT + "  " + NOR + "
        " + BBLU + " " + BLU + "" + BBLK + "◣" + BLK + "" + BWHT + "▃    " + NOR + "▄" + BLK + "" + BWHT + "      ▁   " + NOR + "▇" + HBWHT + "  " + NOR + "
        " + BBLU + "    " + BLU + "" + BBLK + "▅▅" + NOR + "▄" + WHT + "" + BBLK + "▅▄▄" + NOR + "▂▄" + WHT + "" + BBLK + "▆▆▆" + NOR + "

                         \n" + NOR,me);
               message_vision(HIY + "$N幻化成賤兔可愛的模樣，使得$n也跟著裝起可愛來了。\n" + NOR,me,enemy[j]);
                                  {
        if (random(me->query_per()) > 11)
                {
                           for(k=0;k<i;k++)
                           {
                           message_vision(HIW + "$N被賤兔忽然抱住，動彈不得。\n" + NOR,enemy[k]);
                           enemy[k]->receive_wound("kee",2000);
                           enemy[k]->receive_wound("gin",1000);
                           enemy[k]->receive_wound("sen",1000);
                           enemy[k]->start_busy(3);
                           COMBAT_D->report_status(enemy[k]);
                           }
               }
             else
                {
                  message_vision(HIR + "$n使出比賤兔更可愛的模樣，把賤兔給比了下去。\n" + NOR,me,enemy[k]);
                }
                  return 1;
}
}

