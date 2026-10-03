/*
*
* Copyright 2019 FIWARE Foundation e.V.
*
* This file is part of Orion-LD Context Broker.
*
* Orion-LD Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion-LD Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion-LD Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* orionld at fiware dot org
*
* Author: Ken Zangelin
*/
extern "C"
{
#include "ktrace/kTrace.h"                                       // KT_*
#include "kjson/KjNode.h"                                        // KjNode
}

#include "orionld/common/CHECK.h"                                // CHECKx()
#include "orionld/common/SCOMPARE.h"                             // SCOMPAREx
#include "orionld/common/orionldState.h"                         // orionldState
#include "orionld/types/OrionldGeoLocation.h"                    // OrionldGeoLocation
#include "orionld/payloadCheck/pcheckGeoPropertyValue.h"         // pcheckGeoPropertyValue
#include "kjson/kjLookup.h"                                          // kjLookup
#include "orionld/kjTree/kjTreeToGeoLocation.h"                  // Own Interface



// -----------------------------------------------------------------------------
//
// kjTreeToGeoLocation -
//
bool kjTreeToGeoLocation(KjNode* geoLocationNodeP, OrionldGeoLocation* locationP)
{
  // pCheckGeoPropertyValue validates the GeoProperty value structure only;
  // it does NOT extract type or coordinates. The caller must do that via kjLookup.
  // NOTE: this fixes a pre-existing call-site mismatch where kjTreeToGeoLocation.cpp
  // called the old 4-arg signature but a6ee7b61a refactored the function to 2 args.
  if (pCheckGeoPropertyValue(geoLocationNodeP, geoLocationNodeP->name) == false)
  {
    KT_E("pcheckGeoProperty failed");
    orionldState.httpStatusCode = 400;
    return false;
  }

  // Extract /type and /coordinates using kjLookup (kjLookup.h provides extern "C" guard)
  KjNode* typeNodeP       = kjLookup(geoLocationNodeP, "type");
  KjNode* coordsNodeP     = kjLookup(geoLocationNodeP, "coordinates");
  locationP->geoType       = (typeNodeP != NULL) ? typeNodeP->value.s : NULL;
  locationP->coordsNodeP   = coordsNodeP;

  return true;
}
