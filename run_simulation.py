import os
import subprocess

# Path to the gem5 binary that contains all the built files for simulation
gem5_binary = "gem5/build/X86/gem5.opt"

# Path to the configuration script which imports required classes and accepts simulation arguments
config_script = "gem5/configs/deprecated/example/se.py"

# Define the list of workloads to simulate
workloads = [
    # Uncomment and modify to run a different workload; note larger workloads like fft may take more time
    #"gem5/SPEC.Small/fft/fft",
    "gem5/SPEC.Small/mcf/mcf",
]

# Placeholder for additional workload options
work_options = []

# Construct the command to run with the specified workloads
cmd = ";".join(workloads)
opt = ";".join(work_options)

# Specify simulation parameters
general_options = f'--options="{opt}"'
num_cpus = "-n 1"  # Number of CPUs to simulate
cpu_type = "--cpu-type=O3CPU"  # CPU type configuration

# Cache configuration
l1d_size = "--l1d_size=32kB"  # L1 data cache size
l1i_size = "--l1i_size=32kB"  # L1 instruction cache size
l2_size = "--l2_size=512kB"  # L2 cache size
mem_size = "--mem-size=512MB"  # Memory size
l1d_assoc = "--l1d_assoc=2"  # L1 data cache associativity
l1i_assoc = "--l1i_assoc=2"  # L1 instruction cache associativity
l2_assoc = "--l2_assoc=8"  # L2 cache associativity

# Enable caches and set cache replacement policies
caches = "--caches"
l2cache = "--l2cache"
l1d_rp = "--l1d-rp-type=TreePLRURP"
l1i_rp = "--l1i-rp-type=TreePLRURP"
l2_rp = "--l2-rp-type=TreePLRURP"
l1i_wp = "--l1i-wb-clean=True"
l1d_wp = "--l1d-wb-clean=False"
l2_wp = "--l2-wb-clean=True"

# Optional simulation parameters (uncomment to use)
# maxTick = "-m 500000000"  # Maximum number of ticks for the simulation
# warmup = "-W 100000"  # Warmup period for the simulation

# Construct the full command to run the simulation
command = [
    gem5_binary,
    config_script,
    f'--cmd="{cmd}"',
    general_options,
    num_cpus,
    caches,
    l2cache,
    cpu_type,
    l1d_size,
    l1i_size,
    l2_size,
    mem_size,
    l1d_assoc,
    l1i_assoc,
    l2_assoc,
    l1d_rp,
    l1i_rp,
    l2_rp,
    l1i_wp,
    l1d_wp,
    l2_wp
]

# Execute the command
subprocess.run(" ".join(command), shell=True)