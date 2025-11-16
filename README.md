# GreenWheel
GreenWheel is an application designed to encourage safer and more eco-friendly driving habits. By analyzing real driving data—such as speed, acceleration, and braking patterns—the system awards eco-points for efficient driving and deducts points for harsh or unsafe maneuvers.

The application also uses real map data to determine the posted speed limit for the user’s current location. This allows GreenWheel to accurately detect speeding and provide feedback based on real-world road conditions.

# Features
## Driving Data Analysis
* Tracks speed in relation to real posted speed limits
* Evaluates acceleration and braking behavior
* Generates a second-by-second summary of each drive
* Calculates eco-points per drive, rounded up, never negative

## Progression System
* Stores lifetime accumulated eco-points
* Determines the user’s current level
* Calculates the total points needed for the next level
* Saves all relevant data into json files

# Future Improvements
## Real-Time Monitoring
The long-term goal is to support live data recording, allowing the application to:
* Monitor driver behavior in real time
* Update eco-points live
* Provide instant feedback during a drive

## Leaderboard System
Future versions plan to include:
* Global and local leaderboards
* Weekly and monthly rankings
* Progress comparisons between friends or groups

## Rewards and Incentives
Planned additions include:
* Achievement badges
* Unlockable perks for reaching higher levels
* Visual profile customization options