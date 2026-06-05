// clan_cmds.c by ACKY 04/04/00

#include <ansi.h>
void print_cmd( string cmd , int rank , string str );
mapping cmds = ([]);
int sum=0,i;
string str_cmds="";

int main( object me )
{
        int o=0;
        int len;
        mixed *file;
        string clan_name,clan_id,top,list,sort,*money,*members,*area;
        file = get_dir("/cmds/clan/",-1);
        sum = sizeof(file);
        for( i=0; i<sum; i++ )
                if( file[i][1]!=-2 )    {
                        len=sizeof(file[i][0]);
                        cmds[o] = file[i][0][0..len-3];
                        o++;
                }
        str_cmds += sprintf(HIM + "\n      　　.__________" + HIW + "幫派指令集" + HIM + "__________.\n\n");

        str_cmds += sprintf(HIY + "\n□ 一般 -\n" + NOR);
	print_cmd( "c_goto"    , 3, "幫內瞬間移動" );
	print_cmd( "c_home"    , 4, "回到幫派總部" );
	print_cmd( "c_state"   , 5, "查詢幫派狀態" );
	print_cmd( "c_donate"  , 7, "幫派錢莊捐錢" );
	print_cmd( "c_deposit" , 7, "幫派錢莊存錢" );
	print_cmd( "c_withdraw", 7, "幫派錢莊領錢" );
	print_cmd( "c_in"      , 8, "進入幫派" );
	print_cmd( "c_out"     , 8, "離開幫派" );
	print_cmd( "c_cmds"    , 8, "幫派指令集" );
	print_cmd( "c_index"   , 8, "幫派說明文件" );
	print_cmd( "c_list"    , 8, "狂想空間幫派總覽" );
	print_cmd( "c_view"    , 8, "查詢線上幫派玩家" );

	str_cmds += sprintf( HIC + "\n□ 區域維護 -\n" + NOR );
	print_cmd( "c_board"    , 1, "處理佈告欄" );
	print_cmd( "c_set"	, 2, "設定幫派區域" );
	print_cmd( "c_room_make", 3, "擴大幫派地盤" );
	print_cmd( "c_room_del" , 3, "刪除幫派房間" );
	print_cmd( "c_room_link", 3, "設定區域連結" );
	print_cmd( "c_room_own" , 3, "設定專屬區域" );
	print_cmd( "c_room_des" , 7, "設定區域敘述" );
	print_cmd( "c_room_att" , 7, "設定區域屬性" );
	print_cmd( "c_room_item", 7, "設定景觀敘述" );
	print_cmd( "c_build"    , 7, "建造區域" );
	print_cmd( "c_store"    , 7, "儲存個人物品" );
	print_cmd( "c_take"     , 7, "取出個人物品" );

	str_cmds += sprintf( HIR + "\n□ 內政外交 -\n" + NOR );
	print_cmd( "c_passwd"   , 1, "設定幫派密碼" );
	print_cmd( "c_doc"      , 1, "編寫幫派說明" );
	print_cmd( "c_tax"      , 2, "設定幫派稅率" );
	print_cmd( "c_gatetax"  , 2, "設定幫派關稅" );
	print_cmd( "c_gate"     , 2, "設定閘門狀態" );
	print_cmd( "c_alert"    , 3, "設定警戒狀態" );
	print_cmd( "c_prestige" , 3, "設定威望經費" );
	print_cmd( "c_agree"    , 3, "接受求和" );
	print_cmd( "c_surrender", 3, "求和" );
	print_cmd( "c_war"      , 3, "宣戰" );
	print_cmd( "c_ally"     , 3, "同盟" );
	print_cmd( "c_forgive"  , 3, "特赦令" );
	print_cmd( "c_arrest"   , 3, "幫派通緝令" );
	print_cmd( "c_who"      , 7, "查詢幫派境內玩家" );

	str_cmds += sprintf( HIW + "\n□ 人事處理 -\n" + NOR );
	print_cmd( "c_inherit", 1, "幫主傳位" );
	print_cmd( "c_title"  , 1, "更改稱號" );
	print_cmd( "c_jail"   , 3, "監禁幫眾" );
	print_cmd( "c_member" , 4, "幫眾名單" );
	print_cmd( "c_appoint", 4, "任命某人的位階及職銜" );
	print_cmd( "c_banish" , 4, "開除幫眾" );
	print_cmd( "c_join"   , 4, "加入幫派" );
	print_cmd( "c_hire"   , 4, "招募幫派傭兵" );
	print_cmd( "c_obj"    , 4, "裝備幫派傭兵" );
	print_cmd( "c_move"   , 4, "移動幫派傭兵" );
	print_cmd( "c_order"  , 6, "命令幫眾" );

	if( wizardp(me) )       {
		str_cmds += sprintf( HIY + "\n□ 尚未開放之指令 -\n" + NOR );
		for( i=0; i<sum; i++ )  {
			if( cmds[i] )
				str_cmds+=sprintf("\t%s\n",cmds[i]);
		}
	}
	me->start_more(str_cmds);
	str_cmds="";
	return 1;
}

void print_cmd( string cmd , int rank , string str )
{
        string rank_str;
        for( i=0; i<sum; i++ )
                if( cmds[i]==cmd )      {
                        switch( rank ) {
                        case 1 : rank_str=HIW + "■" + NOR; break;
                        case 2 : rank_str=HIW + "■" + HIC+"■" + NOR; break;
                        case 3 : rank_str=HIW + "■" + HIC+"■" + HIY+"■" + NOR; break;
                        case 4 : rank_str=HIW + "■" + HIC+"■" + HIY+"■" + HIG+"■" + NOR; break;
                        case 5 : rank_str=HIW + "■" + HIC+"■" + HIY+"■" + HIG+"■" + HIB+"■" + NOR; break;
                        case 6 : rank_str=HIW + "■" + HIC+"■" + HIY+"■" + HIG+"■" + HIB+"■" + HIR+"■" + NOR; break;
                        case 7 : rank_str=HIW + "■" + HIC+"■" + HIY+"■" + HIG+"■" + HIB+"■" + HIR+"■" + HIM+"■" + NOR; break;
                        case 8 : rank_str="無限制"; break;
                        }
                        str_cmds += sprintf("\t%-16s   %-22s   %-16s\n", cmd , str , rank_str );
                        map_delete( cmds , i );
                        break;
                }
}
