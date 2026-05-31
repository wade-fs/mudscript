// pkla.c by konn
#include <ansi.h>
#include <pkla.h>
inherit F_CLEAN_UP;

int help(object);

int main(object me, string arg) {
        string bet, pk;
        object pker_master, pker_fighter, officer, where;
        int number,a,b;
        a=random(9)+1;

        seteuid( getuid() );
        if( !interactive(me) ) return 1;
        if( !catch(load_object(PK_START_ROOM)) ) {
            if( !(officer = find_living("pkla officer")) &&
                !(officer = find_object("pkla officer"))    )
                return notify_fail("蔡總管休假去了。\n");
        } else return notify_fail("擂台被拆了啦! 快找巫師來。\n");
        if( !arg ) return help(me);
        arg = lower_case(arg);
        where = environment(me);

// 列印出目前接受挑戰的玩家
        if( arg == "list" ) {
            officer->doing_list(me);
            return 1;
        }

// 查詢玩家的勝敗次數
        else if( arg == "winner" ) {
            officer->doing_winner(me);
            return 1;
        }
/*
// pkla.c 多加一個looker的參數, 巫師也可以用, 並加寫help
        else if( arg == "looker" ) {
            officer->doing_looker(me);
            return 1;
        }
*/
// 巫師不可有以下的參數
/*
        else if( wizardp(me) )
           return notify_fail("巫師不能夠參加擂台賽。\n");
*/

// 鬼魂不能參家pk大賽
        else if( me->is_ghost() ) 
           return notify_fail("鬼魂想作什麼?\n");

// 查替身用參數
	else if( arg == "query" ) {
            tell_object(me, sprintf("你目前所擁有的替身共有%d個。\n",
                            me->query("standby")));
            return 1;
        }

// 押賭注
        else if(sscanf(arg,"bet %s %d", pk, number) == 2) {
           officer->doing_bet(me, pk, number);
           return 1;
        }

// 經驗值太低不行參加
        else if( me->query("combat_exp") < 20000 )
           return notify_fail("你的經驗值不夠, 不能參加。\n");

// 潛能太低不能參加
        else if( (me->query("potential") - me->query("learned_points")) < 200 )
           return notify_fail("你的潛能不夠, 不能參加pk 大賽。\n");
        else if( where->query("no_transmit",1))
         {//特定不能傳送的區域不能參加pkla,免得利用bug.出去!!!!
           return notify_fail("你的聲音被神奇的力量檔住了,蔡總管聽不到。\n");
         }

// 對其他玩家下挑戰書
        else if( arg == "me" ) {
           me->set_temp("pkr",a);
           officer->doing_me(me);
           return 1;
        }

// 接受玩家的挑戰
        else if( arg == "accept" ) {
           write ("你接受挑戰！\n");
           me->set_temp("pkr",a);
           officer->doing_accept(me);
           return 1;
        }

// 放棄叫陣
        else if( arg == "end" ) {
           officer->doing_end(me);
           me->delete_temp("pkr");
           return 1;
        }
        else return help(me);
}

int help(object me) {
        write(@HELP

指令格式: pkla <me>|<accept>|<end>|<list>|<winner>|<bet>|<query>

pkla me       是用來叫陣, 以尋求玩家來與你pk。若想
              放棄可下pkla end。
pkla accept   用來接受對方的挑戰。
pkla end      可用此命令來取消對其他玩家所下的挑戰
              , 若挑戰被接受, 則此命令無效!
pkla list     列出現在接受挑戰的玩家。
pkla winner   可以查詢目前每個人的擂台勝敗次數。
pkla query    可用來查詢你現在所擁有的替身數量。
pkla bet      可以對正在pk的玩家作輸贏的賭注, 其中
              種類只有money。
encourage     可以跟蔡總管換替身。

    格式: pkla bet <玩家> <數量> 

    注意: 若贏得五十場的擂台賽, 則可向蔡總管換取獎
	  勵, 打encourage 就可換獎, 獎勵是「替身」
	  一個

HELP);
        return 1;
}
