//
//  security.c
//  HearthMirror
//
//  Created by Istvan Fehervari on 26/12/2016.
//  Copyright © 2016 com.ifehervari. All rights reserved.
//

#include "security.h"

#ifdef __APPLE__
#include <Security/Authorization.h>

int acquireTaskportRight()
{
    OSStatus stat;
    AuthorizationItem taskport_item[] = {{"system.privilege.taskport:"}};
    AuthorizationRights rights = {1, taskport_item}, *out_rights = NULL;
    AuthorizationRef author;
    
    AuthorizationFlags auth_flags = kAuthorizationFlagExtendRights | kAuthorizationFlagPreAuthorize | kAuthorizationFlagInteractionAllowed | ( 1 << 5);
    
    stat = AuthorizationCreate(NULL, kAuthorizationEmptyEnvironment,auth_flags,&author);
    if (stat != errAuthorizationSuccess)
    {
        return 0;
    }
    
    stat = AuthorizationCopyRights( author, &rights, kAuthorizationEmptyEnvironment, auth_flags, &out_rights);
    if (stat != errAuthorizationSuccess)
    {
        printf("fail");
        return 1;
    }
    return 0;
}
#endif