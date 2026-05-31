//banmultid.c ban multi login by ACKY

#include <login.h>

int ban_multi( object ob )
{
        object *user;
        string ob_ip, ob_id, user_id, *special_ip,rank_status,day,shour;
	int i, max, number, sum,hour;

  special_ip = ({
        "210.70.131.254",  //大安高工
        "163.23.234.30",  //中州技院
        "163.19.163.252", //聯合技院
        "203.203.156.34", //興國管理學院
		});
  number = 0;
  user = users();
  rank_status= "/adm/daemons/securityd.c"->get_status(ob);
  if (rank_status!= "(player)") return 0;

  ob_id = ob->query("id");
  ob_ip = query_ip_number( ob );
        day = ctime(time())[0..2];
        shour = ctime(time())[11..12];
        hour = to_int(shour);
    if( hour < 19 && hour > 7 && day != "Sat" && day != "Sun")
		max = MAX_MULTI_USUAL;
	else
		max = MAX_MULTI_UNUSUAL;
	// 春節過年開放multi
	if(time() > 1074614461 && time() < 1074614461+4*60*60*24)
		max = MAX_MULTI_UNUSUAL;
	
	if( member_array( ob_ip, special_ip )==-1 );
	else	max = MAX_MULTI_SPECIAL;

        sum = sizeof(user);
        for( i=0; i<sum; i++ ) {
          if(wizardp(user[i])) continue;
	  user_id = user[i]->query("id");
	  if (query_ip_number(user[i]) == ob_ip) {
	    if (!(""+SECURITY_D->get_status(user_id)=="(player)"))
	      return 0;
	    else if( user_id != ob_id )
	      number++;
          }
	}

        if( number >= max )
		return number;
        else
                return 0;
}
