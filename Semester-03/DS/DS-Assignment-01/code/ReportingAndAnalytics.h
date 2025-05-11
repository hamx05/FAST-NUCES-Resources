#ifndef REPORTING_AND_ANALYTICS_H
#define REPORTING_AND_ANALYTICS_H

#include "Tickets.h"
#include "Agents.h"
#include "TicketResolutionLogs.h"

// This file will contain functions for reporting and analytics
// Since most of the reporting functionality is already embedded in the other classes,
// we'll just include a few utility functions here

void displaySystemStatistics(TicketsList& TL, TicketQueue& TQ, TicketStack& TS, AgentsList& AL);
void displayOpenTickets(TicketQueue& TQ);
void displayAgentTicketLoad(AgentsList& AL);
void displayTicketResolutionHistory(TicketStack& TS);

#endif // REPORTING_AND_ANALYTICS_H