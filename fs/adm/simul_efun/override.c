// file: /adm/simul_efun/override.c
// to override some driver efun
// Swinger (May 1, 97)  -       created this file
//                      -       add snoop()

nomask varargs object snoop(object snooper, object snoopee)
{
        if(!wizardp(snooper))   return 0;
	if(!snoopee) return efun::snoop(snooper);
        if(SECURITY_D->get_wiz_level(snooper)
          <= SECURITY_D->get_wiz_level(snoopee) ||(
          SECURITY_D->get_status(snooper) != "(manager)" &&
          SECURITY_D->get_status(snooper) != "(guest)" &&
          SECURITY_D->get_status(snooper) != "(admin)" &&
          SECURITY_D->get_status(snooper) != "(arch)"  &&
          SECURITY_D->get_status(snooper) != "(wizard)"))
	        {
                log_file("wiz/snoop",sprintf("%s(%s) attempt to snoop %s(%s) %s\n"
,snooper->query("name"),snooper->query("id"),snoopee->query("name"),snoopee->query("id")
,ctime(time()) ));
		tell_object(snoopee,snooper->query("id")+" attempt to snoop you\n");
                return 0;
	        }	
         if( wizhood(snooper) != "(manager)"
            &&  wizhood(snooper) != "(admin)"
            &&  wizhood(snooper) != "(guest)"
            &&  wizhood(snooper) != "(arch)"  
            &&  wizhood(snooper) != "(wizard)"
            )
	    {
                log_file("wiz/snoop",sprintf("%s(%s) attempt to snoop %s(%s) %s\n"
,snooper->query("name"),snooper->query("id"),snoopee->query("name"),snoopee->query("id")
,ctime(time()) ));
		tell_object(snoopee,snooper->query("id")+" attempt to snoop you\n");
	    return 0;
	    }           
        return efun::snoop(snooper,snoopee);
}
