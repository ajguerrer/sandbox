FROM ubuntu
RUN apt-get update && apt-get install -y \
  zsh \
  curl \
  gnupg
ADD https://git.grml.org/f/grml-etc-core/etc/zsh/zshrc /root/.zshrc

RUN echo "deb [arch=amd64] http://storage.googleapis.com/bazel-apt stable jdk1.8" | \
  tee /etc/apt/sources.list.d/bazel.list
RUN curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
RUN apt-get update && apt-get install -y bazel && rm -rf /var/lib/apt/lists/*

WORKDIR /root/workdir
ENTRYPOINT [ "zsh" ]