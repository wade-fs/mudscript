/************************************************************
*  clan_war.c by ACKY 06.22.00                              *
************************************************************/

#include <ansi.h>

inherit F_CLEAN_UP;

int     investigate_player( string *player );
int     help( object me );

int main( object me, string cmd )
{
        string  input, arg, type, clan, cid_who, *player;
        object  officer;

        seteuid( getuid() );

        if( !interactive(me) )
                return 1;

        if( !(officer = find_living("clan_war officer")) && !(officer = find_object("clan_war officer")) )
                return notify_fail( "鄭總管休假去了。\n" );

        if( !me->query("clan" ) )
                return notify_fail( "您沒有加入任何幫派。\n" );

        if( !cmd || cmd == "" )
                return help(me);

// 查詢目前幫派戰爭狀況
        if( cmd == "list" ) {
                officer->do_list( me );
                return 1;
        }

// 查詢戰績, 兌換替身
        else if( cmd == "exchange" ) {
                officer->do_exchange( me );
                return 1;
        }

        sscanf( cmd, "%s %s", type, arg );
        cid_who   = me->query("clan/id");
        player    = allocate( 6 );
        player[0] = me->query("id");

// [ 5 ] vs [ 5 ] 單挑制
        if( type == "multipk" ) {
                if( sscanf ( arg, "%s %s %s %s %s %s",
                        clan, player[1], player[2], player[3], player[4], player[5] ) != 6 )
                        return help(me);
                if( me->query("clan/rank") > 4 )
                        return notify_fail( "您無權使用此指令。\n" );
                if( clan == cid_who )
                        return notify_fail( "不可以內戰喔!\n" );
                if( (CLAN_D->clan_query( clan, "score" )-CLAN_D->clan_query( cid_who, "score" ))>100 )
                        return notify_fail( "對方不屑與小幫派交手, 還是先和弱一點的幫派磨練一下吧。\n" );
                if( (CLAN_D->clan_query( cid_who, "score" )-CLAN_D->clan_query( clan, "score" ))>100 )
                        return notify_fail( "別欺負小幫派啦, 找實力相當的幫派吧。\n" );
                if( !investigate_player( player ) )
                        return 1;
                officer->do_multipk( CLAN_D->clan_query( clan, "name" ), player );
                return 1;
        }

// [ 5 ] vs [ 5 ] 團體戰
        else if( type == "melee" ) {
                if( me->query("clan/rank") > 4 )
                        return notify_fail("您無權使用此指令。\n");

                return notify_fail("此功\能尚未開放。\n");
//              if( investigate_player( clan_id, player )
//                      officer->do_melee( player );
//              return 1;
        }

// [clan]vs[clan] 幫派戰爭
        else if( type == "war" ) {
                if( me->query("clan/rank") > 3 )
                        return notify_fail("您無權使用此指令。\n");

                return notify_fail("此功\能尚未開放。\n");
//              officer->do_war(me);
//              return 1;
        }

// 終止宣戰
        else if( type == "end" ) {
                if( sscanf ( arg, "%s %s", type, clan ) != 2 )
                        return help(me);
                officer->do_end( me, type, CLAN_D->clan_query( clan, "name") );
                return 1;
        }

// 判定勝負        
        else if( type == "judge" )
                if( me->query_temp( "war/type" ) == "multipk" ) {
                        officer->multipk_judge( me );
                        return 1;
                }
        else
                return help(me);
}

int help( object me ) {
        
        me->start_more(HIW"     [指令]  clan_war 幫派戰爭

      "HIR"1"NOR"."HIC"[說明]  multipk [幫派] [名單] : [ 5 ] vs [ 5 ] 單挑制"NOR"
        "HIY"[範例]  clan_war multipk Red_Fire acky anmy bss chan wataru"NOR"
        "HIG"[名單]  參戰者 ID, 依序為第一區~第五區"NOR"

      "HIR"2"NOR"."HIC"[說明]  melee [幫派] [名單]   : [ 5 ] vs [ 5 ] 團體制     (尚未開放)"NOR"
        "HIY"[範例]  clan_war melee orient acky anmy bss chan wataru"NOR"

      "HIR"3"NOR"."HIC"[說明]  war [幫派]            : [clan]vs[clan] 幫派戰爭   (尚未開放)"NOR"
        "HIY"[範例]  clan_war war hero"NOR"

      "HIR"4"NOR"."HIC"[說明]  end [型式] [幫派]     : 終止宣戰"NOR"
        "HIY"[範例]  clan_war end multipk 13_luck"NOR"
        "HIG"[型式]  欲終止之型式, turn, melee, war"NOR"

      "HIR"5"NOR"."HIC"[說明]  judge                 : 請鄭總管判定勝負"NOR"

      "HIR"6"NOR"."HIC"[說明]  list                  : 查詢各幫宣戰情況"NOR"

      "HIR"7"NOR"."HIC"[說明]  exchange              : 兌換替身"NOR"
        "NOR"[備註]  每達1000點戰績, 可兌換一名替身"NOR"

        "HIG"[區域]  1.迅雷峰 2.疾風崖 3.玄冰島 4.烈燄谷 5.震天原"NOR"

                                                by ACKY 06/24/00
");
        return 1;
}

// 查核參戰玩家是否在線上, 是否為參戰幫派之幫眾
int investigate_player( string *player )
{
        int i;
        string clan_id;
        object ob;

        if( !ob = find_player(player[0]) )
                return 0;
        clan_id = ob->query("clan/id");

        for( i=1; i<6; i++) {
                if( !ob = find_player(player[i]) ) {
                        write( "參戰玩家需為貴幫線上之幫眾。\n" );
                        return 0;
                }
                if( ob->query("clan/id") != clan_id || ob->is_ghost() ) {
                        write( "參戰玩家需為貴幫線上之幫眾。\n" );
                        return 0;
                }
                if( ob->query("combat_exp") < 3000000 ) {
                        printf( "%s(%s)實戰經驗都還未滿三百萬, 就急著上戰場當炮灰, 不太好吧。\n", ob->query("name"), ob->query("id") );
                        return 0;
                }
        }
        return 1;
}

                
