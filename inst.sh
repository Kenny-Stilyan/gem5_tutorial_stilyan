# Initialize the codespace environment
# Steps to start a new codespace:
# 1. Navigate to the repository
# 2. Click on "Code" -> "Codespace" -> "Three dots [...]" -> "New with options" -> "Create"
# Now Github codespace will be created

# Install the necessary dependencies
sudo apt update
sudo apt install python3-pip  # Install pip for Python 3
pip3 install -r requirements.txt  # Install Python dependencies from requirements file
sudo apt install m4  # Install m4 macro processor
pip3 install scons  # Install scons build system

# Build the gem5 binary
# Note: This process can take from 15 minutes to a few hours depending on system resources
cd gem5
scons build/X86/gem5.opt -j$(nproc)  # Use all available processor cores for building

# Run the simulation script
cd ..
python3 run_simulation.py

# Output files
# After running, a new folder named "m5out" will be created.
# This folder contains files like "stats.txt" and "config.json", which store simulation outputs such as cache hits and misses.
