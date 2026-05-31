inherit F_CLEAN_UP;

int main(object me, string name)
{
   string msg;
   object ob;
   int	  login_time, current;

   seteuid(getuid(me));

   if( !name ) ob = me;
   else if (!wizardp(me))
     return notify_fail ("你是他老婆啊，查勤查那麼嚴。\n");
   else ob = find_player(name);
   if( !ob ) return notify_fail ( "目前線上無此人。\n" );
// by konn  把系統時間調整回現實時間
//   current = time();
   current = LOGIN_D->query_time();
   login_time = ob->query_temp("login_time");

   msg  = sprintf( "現在中原標準時間為: %s\n\n", ctime(current) );
   msg += sprintf( "%s是%s連線進來的。\n",
                    name?ob->name():"你",
                    CHINESE_D->chinese_time(login_time) ); 
   if ((login_time=current-login_time) >= 60)
     msg += sprintf( "%s此次上線時間至目前為止共%s。\n",
                      name?ob->name():"你",
                      CHINESE_D->chinese_period( login_time ));

   msg += sprintf( "%s這週的第一天是從%s開始起算的．\n",
                    name?ob->name():"你",
                    CHINESE_D->chinese_time(ob->query("一週") )); 

   msg += sprintf( "%s這週已經上線%s．\n",
                    name?ob->name():"你",
                    CHINESE_D->chinese_period(ob->query("一週上線時間") )); 

   if (!name)
     if (login_time > 86400)
       msg += "\nㄛ喔，這樣不行喔，不分晝夜的玩泥巴會搞壞身子ㄋㄟ。\n";
     else if (login_time > 28800)
       msg += "\n哇哩，你上線也未免太久了吧，趕快去辦正事啦。\n";
     else if (login_time > 14400)
       msg += "\n嗯，該考慮考慮現實生活了吧。\n";
     else
       msg += "\n希望狂想空間讓您思想奔放!!\n";

   write (msg);
   return 1;
}

int help(object me)
{
   write( @HELP
指令格式 : date						一般用法
	   date <人名>					巫師專用
指令說明 :
           這個指令告訴你臺灣現在的時刻，並同時告知你何時上線，
         以及上線多久了。
其他參考 :
           time，uptime
HELP );
   return 1;
}
