 string start_time(object me,string dir);
string finish_time(object me,string dir);
string count_time(object me,string dir);

string start_time(object me,string dir)
{
int time;

        time = uptime();
        if( !me->query_temp("/"+dir+"/start_time") )
                me->set_temp("/"+dir+"/start_time",time);
}

string finish_time(object me,string dir)
{
int time;

        time = uptime();
        if( !me->query_temp("/"+dir+"/finish_time") )
                me->set_temp("/"+dir+"/finish_time",time);
}

string count_time(object me,string dir)
{
        int s,m,h,d,st,fi,n;
        string str;

        if( !me->query_temp("/"+dir+"/start_time") )
                return "沒有起始時間";
        if( !me->query_temp("/"+dir+"/finish_time") )
                return "沒有終結時間";

        st = me->query_temp("/"+dir+"/start_time");
        fi = me->query_temp("/"+dir+"/finish_time");

        if( st >= fi )  return "時間錯誤\n";

        n = fi - st;
                me->set_temp("/"+dir+"/count_time",n);

        s = n % 60;
        n /= 60 ;
        m = n % 60;
        n /= 60 ;
        h = n % 24 ;
        n /= 24 ;
        d = n ;
                str = "總計費時 ";
        if ( d )        str += chinese_number(d)+"天";
        if ( h )        str += chinese_number(h)+"小時";
        if ( m )        str += chinese_number(m)+"分";
        if ( s )        str += chinese_number(s)+"秒";
        return str;
}
