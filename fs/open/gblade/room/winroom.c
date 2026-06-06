#include <ansi.h>
inherit ROOM;

void create() {
        set("short","蔡總管的家");
        setup();
}

void init() {
        int i;
        object enemy,me,*user;

        me = this_object();
        if(!me->query_temp("fight")) {
           write("你來這裡作什麼?\n");
           return ;
        }
        enemy = find_player(me->query_temp("enemy"));
        tell_object(me,HIY + "蔡總管說道: 比賽結束!\n" + NOR);
        tell_object(enemy,HIY + "蔡總管說道: 比賽結束!\n" + NOR);
        me->remove_all_killer();
        enemy->remove_all_killer();
        shout(HIC + "蔡總管喝道: 比賽勝負已分! "HIW+me->name()+HIC"慘"+
              "遭屠戮..., 勝者"HIW+enemy->name()+"!\n" + NOR);
        me->add("potential", -100);
        enemy->add("potential", 100);
        me->pay_money(100000);
// 清除五個變數!
       if(me->query_temp("pker"))
          me->delete_temp("pker");
       else me->delete_temp("pker_master");
       if(enemy->query_temp("pker"))
          enemy->delete_temp("pker");
       else enemy->delete_temp("pker_master");
       me->delete_temp("fight");
       enemy->delete_temp("fight");
       me->delete_temp("pk_room");
       enemy->delete_temp("pk_room");
       me->delete_temp("enemy");
       enemy->delete_temp("enemy");
       me->delete_temp("go_away");
       enemy->delete_temp("go_away");
       me->set("eff_kee", 100);
       me->set("kee", 100);
// 再把因pkla 所中的毒解掉!
       me->apply_condition("dark_poison", 0);
       me->apply_condition("five_poison", 0);
       me->apply_condition("rose_poison", 0);
       me->apply_condition("snake_poison", 0);
me->apply_condition("scorpion_poison",0);
       me->apply_condition("burn", 0);
       enemy->apply_condition("dark_poison", 0);
       enemy->apply_condition("five_poison", 0);
       enemy->apply_condition("rose_poison", 0);
       enemy->apply_condition("snake_poison", 0);
       enemy->apply_condition("burn", 0);
// 把player 送走!
       me->move(me->query("startroom"));
       enemy->move(enemy->query("startroom"));
       tell_object(enemy,HIR + "蔡總管告訴你: pk 獲勝, 得到一些潛能! "+
                         "歡迎下次再來!\n" + NOR);
       tell_object(me,HIR + "蔡總管告訴你: pk 敗陣, 罰你跪一個月算盤! "+
                      "抽你現金10 金, 並扣5% 的潛能, 希望你好好練,"+
                         " 下次再來!\n" + NOR);
// 判斷有押賭注的玩家輸贏
        user = users();
        for(i=0; i<sizeof(user); i++) {
           if(user[i]->query_temp("pkla_pker")) {
              if(user[i]->query_temp("pkla_pker") == me->query("id"))
                 tell_object(user[i],
                             HIR + "蔡總管告訴你: 很抱歉! 有賭有賠, 請看開點!\n" + NOR
);
              else {
                 if(user[i]->query_temp("pkla_kind") == "money")
                    user[i]->pay_player(1.5*user[i]->query_temp("pkla_number"));
                 else
                    user[i]->add(user[i]->query_temp("pkla_kind"),
                                 1.5*user[i]->query_temp("pkla_number"));
                 tell_object(user[i],
                             HIR + "蔡總管告訴你: 恭喜你賭場大勝! 歡迎下次再來!\n" + NOR);
                 tell_object(user[i],
                             HIR + "蔡總管告訴你: 奉大神命令, 需把所贏部份繳交一半
X來!\n");
              }
              user[i]->delete_temp("pkla_pker");
              user[i]->delete_temp("pkla_kind");
              user[i]->delete_temp("pkla_number");
           }
        }
}
