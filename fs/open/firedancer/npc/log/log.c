string time_string(int time);
			//時間參數
string write_log(object me,string str);		//log檔參數

string write_log(object me,string str)		//me:誰 str:為何紀錄
{
	write_file("/open/area/fortress/npc/log/kill_leader",sprintf("%s(%s)於%s %s\n",me->name(1),getuid(me),time_string(time()),str) );
}

string time_string(int time)

{

	return "民國"+(int)(localtime(time)[5]-1911)+"年"+(localtime(time)[4]+1)+"月"
		+localtime(time)[3]+"號(星期"+chinese_number(localtime(time)[6])+")"+localtime(time)[2]
		+"點"+localtime(time)[1]+"分"+localtime(time)[0]+"秒";

}
